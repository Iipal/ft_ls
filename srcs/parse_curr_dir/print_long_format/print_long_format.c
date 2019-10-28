/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 22:15:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_long_format_listing.h"

static void	s_print_link(char const *const path)
{
	size_t const	buff_size = 128;
	char			buff[buff_size];

	ft_memset(buff, 0, sizeof(char) * buff_size);
	IFDO(0 > readlink(path, buff, buff_size), DEF_STRERR("ls", path));
	ft_printf(" -> %s", buff);
}

void		plf_obj(char const *const path, InDirObject const *const obj)
{
	char		*fmt_str;
	t_blkcnt_t	dummy_total;

	dummy_total = 0;
	fmt_str = prepare_output_fmtstr(precalc_output(1, obj, &dummy_total));
	ft_printf(fmt_str,
		plf_get_permission((char[STR_LEN_PERMISSION]){ 0 }, obj->stat->st_mode),
		obj->stat->st_nlink, getpwuid(obj->stat->st_uid)->pw_name,
		getgrgid(obj->stat->st_gid)->gr_name, obj->stat->st_size,
		plf_get_date((char[STR_LEN_DATE]) { 0 }, obj->stat->st_ctime), path);
	if (S_ISLNK(obj->stat->st_mode))
		s_print_link(path);
	ft_putchar('\n');
	free(fmt_str);
}

void		plf_objs(size_t const n_objs, InDirObject const *const objs)
{
	char		*fmt_str;
	LFCurrData	data;
	t_blkcnt_t	total;
	size_t		i;

	i = ~0ULL;
	total = 0L;
	data.date = (char[STR_LEN_DATE]) { 0 };
	data.permission = (char[STR_LEN_PERMISSION]) { 0 };
	fmt_str = prepare_output_fmtstr(precalc_output(n_objs, objs, &total));
	ft_printf("total %d\n", total);
	while (n_objs > ++i)
	{
		data = (LFCurrData) { plf_get_date(data.date, objs[i].stat->st_ctime),
					plf_get_permission(data.permission, objs[i].stat->st_mode),
					getpwuid(objs[i].stat->st_uid)->pw_name,
					getgrgid(objs[i].stat->st_gid)->gr_name };
		ft_printf(fmt_str, data.permission, objs[i].stat->st_nlink,
			data.pw_name, data.gr_name, objs[i].stat->st_size, data.date,
			objs[i].dirent->d_name);
		if (S_ISLNK(objs[i].stat->st_mode))
			s_print_link(objs[i].dirent->d_name);
		ft_putchar('\n');
	}
	FREE(fmt_str, free);
}
