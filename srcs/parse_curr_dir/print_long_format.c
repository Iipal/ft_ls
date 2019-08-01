/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/01 12:02:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_long_format_listing.h"

static void	s_get_permission(char *const perm_str, mode_t const st_mode_perm)
{
	perm_str[0] = (S_ISDIR(st_mode_perm))  ? 'd' : '-';
	perm_str[1] = (st_mode_perm & S_IRUSR) ? 'r' : '-';
	perm_str[2] = (st_mode_perm & S_IWUSR) ? 'w' : '-';
	perm_str[3] = (st_mode_perm & S_IXUSR) ? 'x' : '-';
	perm_str[4] = (st_mode_perm & S_IRGRP) ? 'r' : '-';
	perm_str[5] = (st_mode_perm & S_IWGRP) ? 'w' : '-';
	perm_str[6] = (st_mode_perm & S_IXGRP) ? 'x' : '-';
	perm_str[7] = (st_mode_perm & S_IROTH) ? 'r' : '-';
	perm_str[8] = (st_mode_perm & S_IWOTH) ? 'w' : '-';
	perm_str[9] = (st_mode_perm & S_IXOTH) ? 'x' : '-';
}

void	s_precalc_output_width(size_t const n_objs,
			InDirObject const *const objs,
			LongFormatCurrData *const fmt_data)
{
	size_t i;
	size_t max_nlink_width;
	size_t max_size_width;

	i = ~0ULL;
	max_nlink_width = 0;
	max_size_width = 0;
	while (n_objs > ++i)
	{
		if (ft_digits(objs[i].stat->st_nlink) > max_nlink_width)
			max_nlink_width = ft_digits(objs[i].stat->st_nlink);
		if (ft_digits(objs[i].stat->st_size) > max_size_width)
			max_size_width = ft_digits(objs[i].stat->st_size);
	}
	fmt_data->st_nlink_width = max_nlink_width;
	fmt_data->st_size_width = max_size_width;
}

char	*s_prepare_output_fmtstr(char *fmt_str,
			LongFormatCurrData const *const data)
{
	char	*tmp;

	fmt_str = (char[]){ "%s %." };
	tmp = ft_itoa(data->st_nlink_width);
	fmt_str = ft_strncat(fmt_str, tmp, ft_strlen(tmp));
	free(tmp);
	fmt_str = ft_strncat(fmt_str, "d %s %s %.", sizeof("d %s %s %."));
	tmp = ft_itoa(data->st_size_width);
	fmt_str = ft_strncat(fmt_str, tmp, ft_strlen(tmp));
	free(tmp);
	fmt_str = ft_strncat(fmt_str, "d %d %s\n", sizeof("d %d %s\n"));
	return (fmt_str);
}

void	print_long_format(size_t const n_objs, InDirObject const *const objs)
{
	char				*fmt_str;
	LongFormatCurrData	data;
	size_t				i;

	i = ~0ULL;
	fmt_str = NULL;
	s_precalc_output_width(n_objs, objs, &data);
	fmt_str = s_prepare_output_fmtstr(fmt_str, &data);
	ft_printf("%s\n", fmt_str);
	while (n_objs > ++i)
	{
		data = (LongFormatCurrData) { (char[STR_LEN_DATE]){ 0 },
									(char[STR_LEN_PERMISSION]){ 0 },
									getpwuid(objs[i].stat->st_uid),
									getgrgid(objs[i].stat->st_gid),
									data.st_nlink_width, data.st_size_width};
		s_get_permission(data.permission, objs[i].stat->st_mode);
		printf(fmt_str, data.permission,
			objs[i].stat->st_nlink, data.pw->pw_name, data.gp->gr_name,
			objs[i].stat->st_size, objs[i].stat->st_ctime,
			objs[i].dirent->d_name);
	}
}
