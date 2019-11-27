/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:04:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/27 14:53:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SYSTEM_H
# define LS_SYSTEM_H

# include <stdbool.h>

# ifdef __PFUNC__
#  undef __PFUNC__
# endif
# define __PFUNC__ __PRETTY_FUNCTION__

extern bool	get_term_win_size(void);

#endif
