/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 19:25:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_long_format_listing.h"

static void	s_print_link(char *const file)
{
	char	*buff;
	char	*buff_path;

	buff = (char*)ft_memalloc(sizeof(char) * 256);
	buff_path = (char*)ft_memalloc(sizeof(char) * 256);
	readlink(u_full_path(buff_path, g_src_path, file), buff, 256);
	FREE(buff_path, free);
	ft_printf(" -> %s", buff);
	FREE(buff, free);
}

void		plf_obj(char *fmt_str, char *const path,
				InDirObject const *const obj, bool const is_free_fmt)
{
	ft_printf(fmt_str,
		plf_get_permission((char[STR_LEN_PERMISSION]){ 0 }, obj->stat->st_mode),
		obj->stat->st_nlink, getpwuid(obj->stat->st_uid)->pw_name,
		getgrgid(obj->stat->st_gid)->gr_name, obj->stat->st_size,
		plf_get_date((char[STR_LEN_DATE]) { 0 }, obj->stat->st_ctime), path);
	if (S_ISLNK(obj->stat->st_mode))
		s_print_link(path);
	ft_putchar('\n');
	if (is_free_fmt)
		FREE(fmt_str, free);
}

void		plf_objs(uint32_t const n_objs, InDirObject const *const objs)
{
	char				*fmt_str;
	t_blkcnt_t			total;
	register uint32_t	i;

	i = ~0U;
	total = 0L;
	fmt_str = plf_fmt_str(plf_width_spec(n_objs, objs, &total));
	ft_printf("total %d\n", total);
	while (n_objs > ++i)
		plf_obj(fmt_str, objs[i].dirent->d_name, &objs[i], false);
	FREE(fmt_str, free);
}