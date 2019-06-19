/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/19 14:44:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include "ls_errno.h"
# include "ls_flags.h"

# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>

# define DIRENT typedef struct dirent Dirent

DIRENT;

struct	s_curr_dir
{
	Dirent	**dirents;
	size_t	in_dir_dirents;
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

strtab	ls_sort_ascii(size_t max_strings, strtab strings_tab);
void	ls_sort_ascii_dirents(const size_t in_dir_dirents, Dirent **dirents);

CurrDir	*ls_init_curr_dir(string path, const Flags *const flags);

bool	ls_parse_flags(string flags, Environment *const env);

void	ls_free(Environment **env);
void	ls_free_curr_dir(CurrDir **curr_dir);

#endif
