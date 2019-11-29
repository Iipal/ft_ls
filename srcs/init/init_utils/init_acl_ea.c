/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_acl_ea.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:19:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:50:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

#if defined (__APPLE__)

inline char
	init_acl_ea(const char *restrict filename)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;

	(void)u_full_path(g_data_buf, g_src_path, filename);
	acl = acl_get_link_np(g_data_buf, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(g_data_buf, NULL, 0, XATTR_NOFOLLOW);
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

inline char
	init_acl_ea(const char *restrict filename)
{
	(void)filename;
	return (' ');
}

#endif
