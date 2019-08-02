/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/02 19:59:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_long_format_listing.h"

static char	*s_get_permission(char *perm_str, mode_t const st_mode_perm)
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
	return (perm_str);
}

static char	*s_get_date(char *date_str, __time_t const date_time)
{
	struct tm	*tm_file;

	tm_file = localtime(&date_time);
	strftime(date_str, STR_LEN_DATE, "%b %e %H:%M", tm_file);
	return (date_str);
}

void		print_long_format(size_t const n_objs,
				InDirObject const *const objs)
{
	char				*fmt_str;
	LongFormatCurrData	data;
	__blkcnt_t			total;
	size_t				i;

	i = ~0ULL;
	total = 0L;
	data.date = (char[STR_LEN_DATE]) { 0 };
	data.permission = (char[STR_LEN_PERMISSION]) { 0 };
	fmt_str = prepare_output_fmtstr(precalc_output(n_objs, objs, &total));
	ft_printf("total %ld\n", total);
	while (n_objs > ++i)
	{
		data = (LongFormatCurrData) {
			s_get_date(data.date, objs[i].stat->st_ctime),
			s_get_permission(data.permission, objs[i].stat->st_mode),
			getpwuid(objs[i].stat->st_uid)->pw_name,
			getgrgid(objs[i].stat->st_gid)->gr_name };
		ft_printf(fmt_str, data.permission,
			objs[i].stat->st_nlink, data.pw_name, data.gr_name,
			objs[i].stat->st_size, data.date,
			objs[i].dirent->d_name);
		ft_putchar('\n');
	}
	free(fmt_str);
}
