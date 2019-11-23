/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:10:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 11:03:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FLAGS_H
# define LS_FLAGS_H

# include "libft.h"
# include "ls_errno.h"

/*
**	Command line options(flags).
**	 Available options:
**	  -1 - Force output to be one entry per line.
**	   This is the default when output is not to a terminal. (BIT_1_ONE)
**	  -a - Include directory entries whose names begin with a dot ‘.’.
**	    (BIT_A_HIDDEN)
**	  -f - Output is not sorted. This option implies -a. (BIT_F_NOT_SORTED)
**	  -l - List in long format. (BIT_L_LIST)
**	  -R - Recursively list subdirectories encountered. (BIT_R_RECURSIVE)
**	  -r - Reverse order while sorting. (BIT_R_REVERSE)
**	  -t - Sort by modification time, newest first. (BIT_T_TIME)
**	  -u - Use file's last access time instead of
**	   last modification time for sorting (-t) or printing. (BIT_U_ACESS)
*/
extern int32_t	g_flags;

# define BIT_L_LIST       (1 << 0)
# define BIT_1_ONE        (1 << 1)
# define BIT_T_TIME       (1 << 2)
# define BIT_F_NOT_SORTED (1 << 3)
# define BIT_R_REVERSE    (1 << 4)
# define BIT_R_RECURSIVE  (1 << 5)
# define BIT_A_HIDDEN     (1 << 6)
# define BIT_U_ACCESS     (1 << 7)

# define F_LIST       'l'
# define F_ONE        '1'
# define F_TIME       't'
# define F_NOT_SORTED 'f'
# define F_REVERSE    'r'
# define F_RECURSIVE  'R'
# define F_HIDDEN     'a'

#endif
