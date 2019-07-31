/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 09:26:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include "ft_printf.h"
# include "ls_errno.h"
# include "ls_flags.h"

# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>

struct			s_in_dir_object
{
	struct dirent	*dirent;
	struct stat		*stat;
};

# define IN_DIR_OBJ typedef struct s_in_dir_object InDirObject

IN_DIR_OBJ;

struct			s_curr_dir
{
	InDirObject	*objs;
	size_t		*obj_name_lens;
	size_t		in_dir_objs;
	size_t		max_obj_len;
};

# define CURR_DIR typedef struct s_curr_dir	CurrDir

CURR_DIR;

struct			s_environment
{
	size_t	ac;
	strtab	sorted_av;
	uint8_t	flags_mask;
};

# define ENVIRONMENT typedef struct s_environment Environment

ENVIRONMENT;

bool			ls(size_t ac, strtab av);

bool			ls_parse_dir(string path, const uint8_t flags);
CurrDir			*ls_init_curr_dir(string path, const uint8_t flags);

strtab			ls_sort_tab_ascii(size_t max_strings, strtab strings_tab);
void			ls_sort_dirents_ascii(const size_t in_dir_objs,
					InDirObject *const objs,
					const bool is_reverse);
void			ls_sort_stats_time(const size_t in_dir_objs,
					InDirObject *const objs,
					const bool is_reverse);

struct dirent	*ls_dup_dirent(struct dirent const *const src);
struct stat		*ls_dup_stat(struct stat const *const src);

bool			ls_parse_flags(string flags, uint8_t *const fmask);

void			ls_free(Environment **env);
void			ls_free_curr_dir(CurrDir **curr_dir);

#endif
