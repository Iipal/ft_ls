/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gdi_maxlen.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:03:12 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:08:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_GDI_MAXLEN_H
# define LS_GDI_MAXLEN_H

# include <sys/types.h>

/*
** Store the max item name lenght in directory which currently parsing.
**	 (Used for corrent default output formating)
*/
extern size_t	*gdi_maxlen_get_ptr(void);
extern void		gdi_maxlen_cmp(size_t len);

# undef GDI_MAXLEN_GET_VALUE
# define GDI_MAXLEN_GET_VALUE() *gdi_maxlen_get_ptr()

#endif /* LS_GDI_MAX_LEN_H */
