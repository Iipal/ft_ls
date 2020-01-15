/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_acl_ea.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:19:47 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:19:37 by tmaluh           ###   ########.fr       */
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

	(void)u_full_path(GDI_DBUF_GET_VALUE(), GDI_SRC_GET_VALUE(), filename);
	acl = acl_get_link_np(GDI_DBUF_GET_VALUE(), ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(GDI_DBUF_GET_VALUE(), NULL, 0, XATTR_NOFOLLOW);
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
