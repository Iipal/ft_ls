/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gdi_isatty.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:52:07 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:01:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_GDI_ISATTY_H
# define LS_GDI_ISATTY_H

/*
** Store the value what was returned from isatty(STDOUT_FILENO).
*/

# include <stdint.h>

extern int32_t	*gdi_isatty_get_ptr(void);
extern void		gdi_isatty_value_init(void);

# undef GDI_ISATTY_GET_VALUE
# define GDI_ISATTY_GET_VALUE() *gdi_isatty_get_ptr()

#endif /* LS_GDI_ISATTY_H */
