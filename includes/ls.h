/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 17:08:17 by tmaluh           ###   ########.fr       */
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

# define STR_SIZE sizeof("drwxrwxrwx")
# define FP_SPECIAL 1

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
	size_t		max_obj_name_len;
	size_t		in_dir_objs;
};

# define CURR_DIR typedef struct s_curr_dir	CurrDir

CURR_DIR;

struct			s_long_format_helper
{
	char	*permission;
};

# define FORMAT_HELPER typedef struct s_long_format_helper LongFormatCurrData

FORMAT_HELPER;

bool			parse_dir(char *path,
					uint8_t const flags);

CurrDir			*init_curr_dir(char const *const path,
					uint8_t const flags);

char			**new_sorted_ascii_tab(size_t const n,
					char **tab);

void			sort_ascii_dirents(size_t const in_dir_objs,
					InDirObject *const objs,
					bool const is_reverse);
void			sort_time_stats(size_t const in_dir_objs,
					InDirObject *const objs,
					bool const is_reverse);

struct dirent	*dup_dirent(struct dirent const *const src);
struct stat		*dup_stat(struct stat const *const src);

bool			parse_flags(char const *flags_str, uint8_t *const flags);

void			free_curr_dir(CurrDir **curr_dir);

#endif
