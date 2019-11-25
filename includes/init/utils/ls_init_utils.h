/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:56:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/25 17:21:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_INIT_UTILS_H
# define LS_INIT_UTILS_H

# include <dirent.h>
# include <sys/stat.h>

extern struct dirent
*dup_dirent(const struct dirent *restrict src);

extern struct stat
*dup_stat(const struct stat *restrict src);

extern bool
init_stat(const char *restrict path, struct stat *restrict buff);

extern bool
init_stat_no_err(const char *restrict path, struct stat *restrict buff);

extern char
init_acl(const char *restrict filename,
	const struct stat *restrict st);

#endif
