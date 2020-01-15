/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gdi_src.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:17:23 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:19:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_GDI_SRC_H
# define LS_GDI_SRC_H

# define GDI_SRC_SIZE 1024

/*
**	Store the dupcliate of argument name which currently parsing.
*/
extern char	*gdi_src_get_ptr(void);

# undef GDI_SRC_GET_VALUE
# define GDI_SRC_GET_VALUE() gdi_src_get_ptr()

#endif /* LS_GDI_SRC_H */
