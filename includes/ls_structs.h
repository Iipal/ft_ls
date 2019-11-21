/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:48:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:55:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_STRUCTS_H
# define LS_STRUCTS_H

# include <dirent.h>
# include <stddef.h>
# include <sys/stat.h>

typedef struct	s_2si
{
	int	x;
	int	y;
}				t_s2si;

typedef struct	s_2sl
{
	long	x;
	long	y;
}				t_s2sl;

struct			s_object
{
	struct dirent	*dirent;
	struct stat		*stat;
	size_t			d_name_len;
	char			acl_ch;
};

struct			s_dir
{
	struct s_object	*objs;
	int32_t			n_objs;
	bool			is_file;
};

struct			s_dir_init
{
	DIR				*dir;
	struct s_object	*obj;
	struct dirent	*d;
	struct stat		st;
	char			*tmp;
};

struct			s_arg
{
	char	*path;
	size_t	path_len;
	bool	is_dir;
	char	dummy[7];
};

#endif
