/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/01 22:23:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_long_format_listing.h"

static WidthSpecific	s_precalc_output_width(size_t const n_objs,
							InDirObject const *const objs)
{
	WidthSpecific	ws;
	size_t			i;

	i = ~0ULL;
	ws.st_nlink_width = 0;
	ws.st_size_width = 0;
	while (n_objs > ++i)
	{
		if (ft_digits(objs[i].stat->st_nlink) > ws.st_nlink_width)
			ws.st_nlink_width = ft_digits(objs[i].stat->st_nlink);
		if (ft_digits(objs[i].stat->st_size) > ws.st_size_width)
			ws.st_size_width = ft_digits(objs[i].stat->st_size);
	}
	return (ws);
}

static char				*s_prepare_output_fmtstr(WidthSpecific const ws)
{
	char	*fmt_str;
	char	*digits_str_tmp;

	MEM(char, fmt_str,
		STR_LEN_DEFAULT_FMT + ft_digits(ws.st_nlink_width)
		+ ft_digits(ws.st_size_width), E_ALLOC);
	ft_strcpy(fmt_str, "%s %");
	digits_str_tmp = ft_itoa(ws.st_nlink_width);
	ft_strcpy(fmt_str + ft_strlen(fmt_str), digits_str_tmp);
	free(digits_str_tmp);
	ft_strcpy(fmt_str + ft_strlen(fmt_str), "jd %s %s %");
	digits_str_tmp = ft_itoa(ws.st_size_width);
	ft_strcpy(fmt_str + ft_strlen(fmt_str), digits_str_tmp);
	free(digits_str_tmp);
	ft_strcpy(fmt_str + ft_strlen(fmt_str), "jd %jd %s");
	return (fmt_str);
}

static void				s_get_permission(char *const perm_str,
							mode_t const st_mode_perm)
{
	perm_str[0] = (S_ISDIR(st_mode_perm))       ? 'd' : '-';
	perm_str[1] = IS_BIT(st_mode_perm, S_IRUSR) ? 'r' : '-';
	perm_str[1] = IS_BIT(st_mode_perm, S_IRUSR) ? 'r' : '-';
	perm_str[2] = IS_BIT(st_mode_perm, S_IWUSR) ? 'w' : '-';
	perm_str[3] = IS_BIT(st_mode_perm, S_IXUSR) ? 'x' : '-';
	perm_str[4] = IS_BIT(st_mode_perm, S_IRGRP) ? 'r' : '-';
	perm_str[5] = IS_BIT(st_mode_perm, S_IWGRP) ? 'w' : '-';
	perm_str[6] = IS_BIT(st_mode_perm, S_IXGRP) ? 'x' : '-';
	perm_str[7] = IS_BIT(st_mode_perm, S_IROTH) ? 'r' : '-';
	perm_str[8] = IS_BIT(st_mode_perm, S_IWOTH) ? 'w' : '-';
	perm_str[9] = IS_BIT(st_mode_perm, S_IXOTH) ? 'x' : '-';
}

void					print_long_format(size_t const n_objs,
							InDirObject const *const objs)
{
	char				*fmt_str;
	LongFormatCurrData	data;
	int64_t				total;
	size_t				i;

	i = ~0ULL;
	total = 0L;
	fmt_str = s_prepare_output_fmtstr(s_precalc_output_width(n_objs, objs));
	while (n_objs > ++i)
	{
		data = (LongFormatCurrData) { (char[STR_LEN_DATE]){ 0 },
									(char[STR_LEN_PERMISSION]){ 0 },
									getpwuid(objs[i].stat->st_uid),
									getgrgid(objs[i].stat->st_gid) };
		s_get_permission(data.permission, objs[i].stat->st_mode);
		ft_printf(fmt_str, data.permission,
			objs[i].stat->st_nlink, data.pw->pw_name, data.gp->gr_name,
			objs[i].stat->st_size, objs[i].stat->st_ctime,
			objs[i].dirent->d_name);
		if ('-' == data.permission[0])
			total += objs[i].stat->st_blocks / 2;
		else
			total += 4;
		ft_putchar('\n');
	}
	ft_printf("total %ld\n", total);
	// free(fmt_str);
}
