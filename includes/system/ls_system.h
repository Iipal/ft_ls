/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:04:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 11:21:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SYSTEM_H
# define LS_SYSTEM_H

# include <stdbool.h>

# ifdef __pfunc__
#  undef __pfunc__
# endif
# define __pfunc__ __PRETTY_FUNCTION__

/*
**	Store size of current terminal widnow.
**	 Using for correct default format output.
*/
extern t_s2si	g_win_size;

extern bool	get_term_win_size(void);

#endif
