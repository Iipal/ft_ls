/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:10:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 21:08:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FLAGS_H
# define LS_FLAGS_H

# include "libft.h"
# include "ls_errno.h"

/*
**	Command line options(flags).
**	 Available options:
**	  -l - Long format listing. (BIT_L_LIST)
**	  -1 - List one file per line. (BIT_1_ONE)
**	  -t - sort by modification time, newest first. (BIT_T_TIME)
**	  -f - don't sorted, enable -a. (BIT_F_NOT_SORTED)
**	  -r - reverse order while sorting. (BIT_R_REVERSE)
**	  -R - list subdirectories recursively. (BIT_R_RECURSIVE)
**	  -a - do not ignore entires starting with '.'. (BIT_A_HIDDEN)
*/
extern int32_t	g_flags;

# define BIT_L_LIST       (1 << 0)
# define BIT_1_ONE        (1 << 1)
# define BIT_T_TIME       (1 << 2)
# define BIT_F_NOT_SORTED (1 << 3)
# define BIT_R_REVERSE    (1 << 4)
# define BIT_R_RECURSIVE  (1 << 5)
# define BIT_A_HIDDEN     (1 << 6)

# define F_LIST       'l'
# define F_ONE        '1'
# define F_TIME       't'
# define F_NOT_SORTED 'f'
# define F_REVERSE    'r'
# define F_RECURSIVE  'R'
# define F_HIDDEN     'a'

#endif
