/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:11:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct s_object
	*init_dir_obj(struct s_object *restrict dst,
		const struct stat *restrict st,
		const struct dirent *restrict dirent,
		const char *restrict filename)
{
	struct s_object *out;

	out = dst;
	if (!out && !(out = ft_memalloc(sizeof(struct s_object))))
		return (ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memmalloc"));
	if (dirent && !(out->dirent = ft_memdup(dirent, sizeof(*dirent))))
		return (free_dir_obj(out));
	if (st && !(out->stat = ft_memdup(st, sizeof(*st))))
		return (free_dir_obj(out));
	out->d_name_len = ft_strlen(filename);
	out->d_name = ft_strndup(filename, out->d_name_len);
	if (g_max_name_len < out->d_name_len)
		g_max_name_len = out->d_name_len;
	out->acl_ch = init_acl_ea(filename, st);
	out->clr_name = init_file_color(filename, out->d_name_len, st,
						&out->clr_len);
	return (out);
}
