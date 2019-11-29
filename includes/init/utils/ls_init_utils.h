/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:56:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 13:01:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_INIT_UTILS_H
# define LS_INIT_UTILS_H

# include "ls_s_stat.h"

extern struct s_stat
*dup_stat(const struct stat *restrict src);

extern bool
init_stat(const char *restrict path, struct stat *restrict buff);

extern bool
init_stat_no_err(const char *restrict path, struct stat *restrict buff);

extern char
init_acl_ea(const char *restrict filename);

#endif
