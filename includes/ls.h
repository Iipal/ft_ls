/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/25 22:13:29 by tmaluh           ###   ########.fr       */
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
extern char		g_data_buf[1024];

#endif
