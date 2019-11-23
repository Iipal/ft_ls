/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 20:00:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline void
	s_print_link(const char *restrict file)
{
	char	*buff;
	char	*buff_path;

	if (!(buff = (char*)ft_memalloc(sizeof(char) * 256UL)))
		return ((void)ls_errno_msg(__FILE__, __PFUNC__, __LINE__, ""));
	if (!(buff_path = (char*)ft_memalloc(sizeof(char) * 256UL)))
		return ((void)ls_errno_msg(__FILE__, __PFUNC__, __LINE__, ""));
	readlink(u_full_path(buff_path, g_src_path, file), buff, 256UL);
	ft_strdel(&buff_path);
	ft_printf(" -> %s", buff);
	ft_strdel(&buff);
}

inline void
	plf_obj(char *restrict fmt_str,
		const char *restrict path,
		const struct s_object *restrict obj,
		const bool is_free_fmt)
{
	ft_printf(fmt_str,
		plf_get_permission((char[STR_LEN_PERMISSION]){ 0 }, obj->stat->st_mode),
		obj->acl_ch,
		obj->stat->st_nlink,
		IS_BIT(g_flags, BIT_G_NOT_OWNER)
			? "" : getpwuid(obj->stat->st_uid)->pw_name,
		getgrgid(obj->stat->st_gid)->gr_name,
		obj->stat->st_size,
		plf_get_date((char[STR_LEN_DATE]) { 0 }, IS_BIT(g_flags, BIT_U_ACCESS)
			? obj->stat->st_atime : obj->stat->st_ctime),
		path);
	if (S_ISLNK(obj->stat->st_mode))
		s_print_link(path);
	ft_putchar('\n');
	if (is_free_fmt)
		ft_strdel((char**)&fmt_str);
}

void
	plf(const int32_t n_objs, const struct s_object *restrict objs)
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
