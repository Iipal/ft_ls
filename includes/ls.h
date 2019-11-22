/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:15:21 by tmaluh           ###   ########.fr       */
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

# include "ls_global_vars.h"

# include "ls_errno.h"

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

#endif
