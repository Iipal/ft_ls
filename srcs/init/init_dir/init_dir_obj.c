/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/26 16:22:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct s_object
	*init_dir_obj(struct s_object *restrict dst,
		const struct stat *restrict stat,
		const struct dirent *restrict dirent,
		const char *restrict filename)
{
	struct s_object	*out;

	out = dst;
	if (!out && !(out = ft_memalloc(sizeof(struct s_object))))
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "malloc"));
	if (dirent && !(out->dirent = dup_dirent(dirent)))
		return (free_dir_obj(out));
	if (stat && !(out->stat = dup_stat(stat)))
		return (free_dir_obj(out));
	out->d_name_len = 0UL;
	if (out->dirent)
	{
		out->d_name_len = ft_strlen(out->dirent->d_name);
		if (g_max_name_len < out->d_name_len)
			g_max_name_len = out->d_name_len;
	}
	out->acl_ch = init_acl_ea(filename, stat);
	return (out);
}
