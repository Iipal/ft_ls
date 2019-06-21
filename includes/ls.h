/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/21 08:48:29 by tmaluh           ###   ########.fr       */
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

struct	s_in_dir_object
{
	struct dirent	*dirent;
	struct stat		*stat;
};

# define IN_DIR_OBJ typedef struct s_in_dir_object InDirObject

IN_DIR_OBJ;

struct	s_curr_dir
{
	InDirObject	*objs;
	size_t		in_dir_objs;
};

# define CURR_DIR typedef struct s_curr_dir	CurrDir

CURR_DIR;

struct	s_environment
{
	size_t	ac;
	strtab	sorted_av;
	Flags	flags;
};

# define ENVIRONMENT typedef struct s_environment Environment

ENVIRONMENT;

bool	ls(size_t ac, strtab av);

strtab	ls_sort_tab_ascii(size_t max_strings, strtab strings_tab);
void	ls_sort_dirents_ascii(const size_t in_dir_objs,
			InDirObject *const objs,
			const bool is_reverse);
void	ls_sort_stats_time(const size_t in_dir_objs,
			InDirObject *const objs,
			const bool is_reverse);

CurrDir	*ls_init_curr_dir(string path, const Flags *const flags);

bool	ls_parse_flags(string flags, Environment *const env);

void	ls_free(Environment **env);
void	ls_free_curr_dir(CurrDir **curr_dir);

#endif
