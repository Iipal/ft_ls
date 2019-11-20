/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_in_dir_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 00:20:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

#if defined (__APPLE__)
static inline char	s_check_acl(const char *restrict filename,
						const struct stat *restrict st)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;
	char		*full_path;

	full_path = u_full_path(ft_strnew(256UL), g_src_path, filename);
	acl = acl_get_link_np(full_path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(full_path, NULL, 0, XATTR_NOFOLLOW);
	ft_strdel(&full_path);
	if (0 > xattr)
		xattr = 0;
	if (0 < xattr)
		return ('@');
	else if (acl != NULL)
	{
		acl_free(acl);
		return ('+');
	}
	return (' ');
}
#elif defined (__linux__)
static inline char	s_check_acl(const char *restrict filename,
						const struct stat *restrict st)
{
	(void)filename;
	(void)st;
	return (' ');
}
#endif

inline InDirObject	*init_curr_in_dir_obj(InDirObject *restrict dst,
						const struct stat *restrict stat,
						const struct dirent *restrict dirent)
{
	InDirObject	*out;

	out = dst;
	if (!out)
		MEM(InDirObject, out, 1, E_ALLOC);
	if (dirent && !(out->dirent = dup_dirent(dirent)))
		return (free_curr_in_dir_obj(out));
	if (stat && !(out->stat = dup_stat(stat)))
		return (free_curr_in_dir_obj(out));
	out->d_name_len = 0UL;
	if (out->dirent)
		out->d_name_len = ft_strlen(out->dirent->d_name);
	if (g_max_name_len < out->d_name_len)
		g_max_name_len = out->d_name_len;
	out->acl_ch = s_check_acl(dirent->d_name, stat);
	return (out);
}
