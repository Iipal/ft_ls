/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 01:18:58 by tmaluh           ###   ########.fr       */
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
	int							p_slash;

	out = dst;
	if (!out && !(out = ft_memalloc(sizeof(struct s_object))))
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "malloc"));
	if (dirent && !(out->dirent = dup_dirent(dirent)))
		return (free_dir_obj(out));
	if (stat && !(out->stat = dup_stat(stat)))
		return (free_dir_obj(out));
	p_slash = IS_BIT(g_flags, BIT_P_DIR_SLASH) && S_ISDIR(stat->st_mode);
	out->d_name_len = ft_strlen(filename) + p_slash;
	if (g_max_name_len < out->d_name_len)
		g_max_name_len = out->d_name_len;
	out->d_name = ft_strndup(filename, out->d_name_len);
	if (p_slash)
		out->d_name[out->d_name_len - 1] = '/';
	out->acl_ch = init_acl_ea(filename, stat);
	return (out);
}
