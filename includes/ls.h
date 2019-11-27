/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/27 14:56:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# define _GNU_SOURCE

# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <math.h>

# include "ls_structs.h"
# include "ls_types.h"
# include "ls_flags.h"

# include "ls_utils.h"
# include "ls_system.h"
# include "ls_parsers.h"
# include "ls_init.h"
# include "ls_sorts.h"
# include "ls_output.h"
# include "ls_free.h"

# include "ls_errno.h"

/*
** What main shoud to return.
** Variable changes only in main.c and parse_args.c
*/
extern int		g_main_ret;

/*
** char buffer for anything.
*/
extern char		g_data_buf[4096];

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
**	  -t - Sort by modification time, newest first. (BIT_T_TIME)
**	  -u - Use file's last access time instead of
**	   last modification time for sorting (-t) or printing. (BIT_U_ACESS)
*/
extern int32_t	g_flags;

/*
**	Store size of current terminal widnow.
**	 Using for correct default format output.
*/
extern t_s2si	g_win_size;

/*
** Store the value what was returned from isatty(STDOUT_FILENO).
*/
extern int32_t	g_isatty_ret;

/*
**	Store the dupcliate of argument name which currently parsing.
*/
extern char		g_src_path[1024];

/*
** Store the max item name lenght in directory which currently parsing.
**	 (Used for corrent default output formating)
*/
extern size_t	g_max_name_len;

#endif
