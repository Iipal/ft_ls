/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:10:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 21:48:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FLAGS_H
# define LS_FLAGS_H

# include "libft.h"
# include "ls_errno.h"

# define BIT_R_REVERSE    (1 << 0)
# define BIT_A_HIDDEN     (1 << 1)
# define BIT_R_RECURSIVE  (1 << 2)

# define F_LIST_CH       'l'
# define F_ONE           '1'

# define F_TIME_CH       't'
# define F_NOT_SORTED_CH 'f'

# define F_REVERSE_CH    'r'

# define F_RECURSIVE_CH  'R'
# define F_HIDDEN_CH     'a'

# define E_ILL_OPT ERR "illegal option -- "
# define E_ILLEGAL(f) {MSG(E_ILL_OPT);ft_putchar_fd(f,2);ft_putchar_fd(10,2);}

# define E_MISS_FLAG ERR "'-' exist but flags missing."

#endif
