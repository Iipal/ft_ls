/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/05 19:12:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_long_format_listing.h"

static char	*s_get_permission(char *perm_str, mode_t const st_mode_perm)
{
	perm_str[0] = '-';
	if (S_ISLNK(st_mode_perm))
		perm_str[0] = 'l';
	else if (S_ISDIR(st_mode_perm))
		perm_str[0] = 'd';
	perm_str[1] = (st_mode_perm & S_IRUSR) ? 'r' : '-';
	perm_str[1] = (st_mode_perm & S_IRUSR) ? 'r' : '-';
	perm_str[2] = (st_mode_perm & S_IWUSR) ? 'w' : '-';
	perm_str[3] = (st_mode_perm & S_IXUSR) ? 'x' : '-';
	perm_str[4] = (st_mode_perm & S_IRGRP) ? 'r' : '-';
	perm_str[5] = (st_mode_perm & S_IWGRP) ? 'w' : '-';
	perm_str[6] = (st_mode_perm & S_IXGRP) ? 'x' : '-';
	perm_str[7] = (st_mode_perm & S_IROTH) ? 'r' : '-';
	perm_str[8] = (st_mode_perm & S_IWOTH) ? 'w' : '-';
	perm_str[9] = (st_mode_perm & S_IXOTH) ? 'x' : '-';
	return (perm_str);
}

static char	*s_get_date(char *date_str, t_time_t const date_time)
{
	static struct tm	*tm_file;

	tm_file = localtime(&date_time);
	strftime(date_str, STR_LEN_DATE, "%b %e %H:%M", tm_file);
	return (date_str);
}

void		print_obj_long_format(char const *const path,
							InDirObject const *const obj)
{
	char		*fmt_str;
	t_blkcnt_t	dummy_total;

	dummy_total = 0;
	fmt_str = prepare_output_fmtstr(precalc_output(1, obj, &dummy_total));
	ft_printf(fmt_str,
		s_get_permission((char[STR_LEN_PERMISSION]) { 0 }, obj->stat->st_mode),
		obj->stat->st_nlink, getpwuid(obj->stat->st_uid)->pw_name,
		getgrgid(obj->stat->st_gid)->gr_name, obj->stat->st_size,
		s_get_date((char[STR_LEN_DATE]) { 0 }, obj->stat->st_ctime),
		path);
	ft_putchar('\n');
	free(fmt_str);
}

void		print_objs_long_format(size_t const n_objs,
				InDirObject const *const objs)
{
	char				*fmt_str;
	LongFormatCurrData	data;
	t_blkcnt_t			total;
	size_t				i;

	i = ~0ULL;
	total = 0L;
	data.date = (char[STR_LEN_DATE]) { 0 };
	data.permission = (char[STR_LEN_PERMISSION]) { 0 };
	fmt_str = prepare_output_fmtstr(precalc_output(n_objs, objs, &total));
	ft_printf("total %d\n", total);
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
