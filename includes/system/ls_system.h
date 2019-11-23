/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:04:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 13:30:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SYSTEM_H
# define LS_SYSTEM_H

# include <stdbool.h>

# ifdef __PFUNC__
#  undef __PFUNC__
# endif
# define __PFUNC__ __PRETTY_FUNCTION__

/*
**	Store size of current terminal widnow.
**	 Using for correct default format output.
*/
extern t_s2si	g_win_size;

/*
** Store the value what was returned from isatty(STDOUT_FILENO).
*/
extern int32_t	g_isatty_ret;

extern bool	get_term_win_size(void);

#endif
