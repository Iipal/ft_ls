/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gdi_dbuf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:11:47 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:16:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_GDI_DBUF_H
# define LS_GDI_DBUF_H

# define GDI_DBUF_SIZE 1024

/*
** char buffer for ACL check and long listing format-string.
*/
extern char	*gdi_dbuf_get_ptr(void);

# undef GDI_DBUF_GET_VALUE
# define GDI_DBUF_GET_VALUE() gdi_dbuf_get_ptr()

#endif /* LS_GDI_DBUF_H */
