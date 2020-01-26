/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gdi_flags.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:30:41 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/25 23:31:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_GDI_FLAGS_H
# define LS_GDI_FLAGS_H

# include <stdint.h>

# include "ls_s_arg_av.h"

/*
**	Command line options(flags).
**	 Available options:
**	  -1 - Force output to be one entry per line.
**	   This is the default when output is not to a terminal. (BIT_1_ONE)
**	  -a - Include directory entries whose names begin with a dot ‘.’.
**	    (BIT_A_HIDDEN)
**	  -f - Output is not sorted. This option implies -a. (BIT_F_NOT_SORTED)
**	  -g - List in long format as in -l,
**	   except that the owner is not printed. (BIT_F_NOT_SORTED)
**	  -l - List in long format. (BIT_L_LIST)
**	  -R - Recursively list subdirectories encountered. (BIT_R_RECURSIVE)
**	  -r - Reverse order while sorting. (BIT_R_REVERSE)
**	  -S - Sort files by size.
**	  -T - Display complete time information for the file. (BIT_T_FULL_TIME)
**	  -t - Sort by modification time, newest first. (BIT_T_TIME)
**	  -u - Use file's last access time instead of
**	   last modification time for sorting (-t) or printing. (BIT_U_ACESS)
*/
extern int32_t	*gdi_flags_get_ptr(void);
extern void		gdi_flags_parser(struct s_arg_av *restrict a);
extern void		gdif_internal_checks(const int32_t mask);

# undef GDI_FLAGS_GET_VALUE
# define GDI_FLAGS_GET_VALUE() *gdi_flags_get_ptr()

# undef GDI_FLAGS_SET_BIT
# define GDI_FLAGS_SET_BIT(mask) (GDI_FLAGS_GET_VALUE() |= (mask))

# undef GDI_FLAGS_UNSET_BIT
# define GDI_FLAGS_UNSET_BIT(mask) (GDI_FLAGS_GET_VALUE() &= ~(mask))

# undef GDI_FLAGS_TOGGLE_BIT
# define GDI_FLAGS_TOGGLE_BIT(mask) (GDI_FLAGS_GET_VALUE() ^= (mask))

# undef GDI_FLAGS_IS_BIT
# define GDI_FLAGS_IS_BIT(mask) (GDI_FLAGS_GET_VALUE() & (mask))

#endif /* LS_GDI_FLAGS_H */
