/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 13:05:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline void
	s_print_link(const char *restrict file)
{
	char	*buff;
	char	*buff_path;

	if (!(buff = (char*)ft_memalloc(sizeof(char) * 1024UL)))
		return ((void)ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc"));
	if (!(buff_path = (char*)ft_memalloc(sizeof(char) * 1024UL)))
		return ((void)ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc"));
	readlink(u_full_path(buff_path, g_src_path, file), buff, 1024UL);
	ft_strdel(&buff_path);
	ft_printf(" -> %s", buff);
	ft_strdel(&buff);
}

inline void
	plf_obj(char *restrict fmt_str,
		const char *restrict path,
		const struct s_object *restrict obj)
{
	ft_printf(fmt_str,
		plf_get_permission((char[STR_LEN_PERMISSION]){ 0 }, obj->st->mode),
		obj->acl_ch,
		obj->st->nlink,
		IS_BIT(g_flags, BIT_G_NO_OWNER)
			? "" : getpwuid(obj->st->uid)->pw_name,
		getgrgid(obj->st->gid)->gr_name,
		plf_get_dev_info((char[STR_LEN_DEVICE]) { 0 }, obj->st),
		plf_get_date((char[STR_LEN_DATE]) { 0 }, obj->st),
		path);
	if (S_ISLNK(obj->st->mode))
		s_print_link(obj->d_name);
	ft_putchar('\n');
}

void
	plf(const int32_t n_objs, const struct s_object *restrict objs)
{
	char		*fmt_str;
	t_blkcnt_t	total;
	int32_t		i;

	i = -1;
	total = 0L;
	fmt_str = plf_get_fmt_str(n_objs, objs, &total);
	if (g_is_print_total)
		ft_printf("total %lld\n", total);
	while (n_objs > ++i)
		plf_obj(fmt_str, (objs[i].clr_name ? objs[i].clr_name : objs[i].d_name),
			&objs[i]);
}
