/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:59:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 21:11:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_INIT_H
# define LS_INIT_H

# include "ls_s_dir.h"

# include "ls_init_utils.h"

extern struct s_dir
*init_dir(const char *path, const bool force_open_dir);

extern struct s_object
*init_dir_obj(struct s_object *restrict dst,
	const struct stat *restrict stat,
	const char *restrict filename);

extern char
*init_file_color(const char *restrict filename,
	const size_t filename_len,
	const mode_t mode,
	size_t *restrict clr_len);

extern struct s_dir
*init_file(const char *restrict path);

#endif
