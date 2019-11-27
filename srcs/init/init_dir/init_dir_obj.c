/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/27 18:06:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct s_object
	*init_dir_obj(struct s_object *restrict dst,
		const struct stat *restrict stat,
		const struct dirent *restrict dirent,
		const char *restrict filename)
{
	struct s_object *restrict	out;

	out = dst;
	if (!out && !(out = ft_memalloc(sizeof(struct s_object))))
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "malloc"));
	out->d_name_len = ft_strlen(filename);
	out->d_name = ft_strndup(filename, out->d_name_len);
	if (dirent && !(out->dirent = dup_dirent(dirent)))
		return (free_dir_obj(out));
	if (stat && !(out->stat = dup_stat(stat)))
		return (free_dir_obj(out));
	if (g_max_name_len < out->d_name_len)
		g_max_name_len = out->d_name_len;
	out->acl_ch = init_acl_ea(filename, stat);
	return (out);
}
