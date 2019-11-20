/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:48:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/20 17:57:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_STRUCTS_H
# define LS_STRUCTS_H

# include <dirent.h>
# include <stddef.h>
# include <sys/stat.h>

struct			s_2si
{
	int	x;
	int	y;
};

struct			s_2sl
{
	long	x;
	long	y;
};

struct			s_in_dir_object
{
	struct dirent	*dirent;
	struct stat		*stat;
	size_t			d_name_len;
	char			acl_ch;
};

# define S2SI typedef struct s_2si s2si
# define S2SL typedef struct s_2sl s2sl
# define IN_DIR_OBJ typedef struct s_in_dir_object InDirObject

S2SI;
S2SL;
IN_DIR_OBJ;

struct			s_curr_dir
{
	InDirObject	*objs;
	int32_t		n_objs;
	bool		is_file;
};

struct			s_curr_dir_init
{
	DIR				*dir;
	InDirObject		*curr;
	struct dirent	*dirent;
	struct stat		stat;
	char			*tmp;
};

# define CURR_DIR      typedef struct s_curr_dir CurrDir
# define CURR_DIR_INIT typedef struct s_curr_dir_init CurrDirInit

CURR_DIR;
CURR_DIR_INIT;

#endif
