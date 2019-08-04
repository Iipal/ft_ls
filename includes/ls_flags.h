/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:10:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/03 21:59:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FLAGS_H
# define LS_FLAGS_H

# include "libft.h"
# include "ls_errno.h"

# define MAX_FLAGS 5

# define F_L_LIST (1 << 0)
# define F_R_REC  (1 << 1)
# define F_A_HDN  (1 << 2)
# define F_R_REV  (1 << 3)
# define F_T_TIME (1 << 4)

# define F_LIST_CH      'l'
# define F_RECURSIVE_CH 'R'
# define F_HIDDEN_CH    'a'
# define F_REVERSE_CH   'r'
# define F_TIME_CH      't'

# define E_ILL_OPT ERR "illegal option -- "
# define E_ILLEGAL(f) {MSG(E_ILL_OPT);ft_putchar_fd(f,2);ft_putchar_fd(10,2);}

# define E_MISS_FLAG ERR "'-' exist but flags missing."

#endif
