/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/03 16:09:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include "ft_printf.h"
# include "ls_errno.h"
# include "ls_flags.h"
# include "ls_structs.h"

# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>

bool			parse_dir(char *path, uint8_t const flags);

void			print_long_format(size_t const n_objs,
					InDirObject const *const objs);
void			print_default_format(size_t const n_objs,
					InDirObject const *const objs);

CurrDir			*init_curr_dir(char *const path,
					uint8_t const flags);

char			**sort_ascii_tab_str(size_t const n, char **tab);
void			sort_ascii_dirents(size_t const objs_counter,
					InDirObject *const objs,
					bool const is_reverse);
void			sort_time_stats(size_t const objs_counter,
					InDirObject *const objs,
					bool const is_reverse);

struct dirent	*dup_dirent(struct dirent const *const src);
struct stat		*dup_stat(struct stat const *const src);

bool			parse_flags(char const *flags_str, uint8_t *const flags);

void			free_curr_dir(CurrDir **curr_dir);

#endif
