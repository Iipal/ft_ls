/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:48:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/05 16:12:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_STRUCTS_H
# define LS_STRUCTS_H

# include <dirent.h>
# include <stddef.h>

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
	size_t		n_objs;
};

struct			s_curr_dir_init
{
	DIR				*m_dir;
	struct dirent	*m_dirent;
	struct stat		*m_stat;
	char			m_path[1024];
};

# define CURR_DIR      typedef struct s_curr_dir CurrDir
# define CURR_DIR_INIT typedef struct s_curr_dir_init CurrDirInit

CURR_DIR;
CURR_DIR_INIT;

#endif
