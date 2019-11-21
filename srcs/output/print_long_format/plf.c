/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 22:02:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_long_format_listing.h"

static void	s_print_link(const char *restrict file)
{
	char	*buff;
	char	*buff_path;

	buff = (char*)ft_memalloc(sizeof(char) * 256UL);
	buff_path = (char*)ft_memalloc(sizeof(char) * 256UL);
	readlink(u_full_path(buff_path, g_src_path, file), buff, 256UL);
	ft_strdel(&buff_path);
	ft_printf(" -> %s", buff);
	ft_strdel(&buff);
}

void		plf_obj(char *restrict fmt_str,
				const char *restrict path,
				const InDirObject *restrict obj,
				const bool is_free_fmt)
{
	ft_printf(fmt_str,
		plf_get_permission((char[STR_LEN_PERMISSION]){ 0 }, obj->stat->st_mode),
		obj->acl_ch, obj->stat->st_nlink, getpwuid(obj->stat->st_uid)->pw_name,
		getgrgid(obj->stat->st_gid)->gr_name, obj->stat->st_size,
		plf_get_date((char[STR_LEN_DATE]) { 0 }, obj->stat->st_ctime), path);
	if (S_ISLNK(obj->stat->st_mode))
		s_print_link(path);
	ft_printf("\n");
	if (is_free_fmt)
		ft_strdel((char**)&fmt_str);
}

void		plf_objs(const int32_t n_objs, const InDirObject *restrict objs)
{
	char		*fmt_str;
	t_blkcnt_t	total;
	int32_t		i;

	i = -1;
	total = 0L;
	fmt_str = plf_fmt_str(plf_width_spec(n_objs, objs, &total));
	ft_printf("total %lld\n", total);
	while (n_objs > ++i)
		plf_obj(fmt_str, objs[i].dirent->d_name, &objs[i], false);
	ft_strdel(&fmt_str);
}
