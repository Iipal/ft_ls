/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_global_vars.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:14:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:14:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_GLOBAL_VARS_H
# define LS_GLOBAL_VARS_H

# include <sys/types.h>

# include "ls_types.h"

extern int32_t	g_flags;
extern char		*g_src_path;
extern size_t	g_max_name_len;
extern t_s2si	g_win_size;
extern int		g_main_ret;

#endif
