/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:27:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 16:16:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	s_check_dirs_recursive(CurrDir *const curr_dir,
			uint8_t const flags,
			char *previous_path)
{
	DIR		*tmp_dir;
	string	full_path;
	size_t	i;

	i = ~0ULL;
	full_path = NULL;
	while (curr_dir->in_dir_objs > ++i)
	{
		if ('/' != previous_path[ft_strlen(previous_path) - 1])
		{
			full_path = ft_strnew(sizeof(char)
				* (ft_strlen(curr_dir->objs[i].dirent->d_name)
				+ ft_strlen(previous_path) + 1));
			full_path = ft_strncpy(full_path, previous_path,
									ft_strlen(previous_path));
			full_path[ft_strlen(previous_path)] = '/';
			full_path = ft_strncat(full_path, curr_dir->objs[i].dirent->d_name,
								ft_strlen(curr_dir->objs[i].dirent->d_name));
		}
		else
			full_path =
				ft_strjoin(previous_path, curr_dir->objs[i].dirent->d_name);
		if (!ft_strcmp(full_path + (ft_strlen(full_path) - 2), "..")
		|| !ft_strcmp(full_path + (ft_strlen(full_path) - 1), "."))
		{
			ft_strdel(&full_path);
			continue ;
		}
		if ((tmp_dir = opendir(full_path)))
		{
			ft_printf("\n%s:\n", full_path);
			parse_dir(full_path, flags);
		}
		ft_strdel(&full_path);
	}
	return (true);
}

static void	s_print_long_format(InDirObject *const obj)
{
	static char		str_perm[STR_SIZE];
	mode_t const	perm = obj->stat->st_mode;

	str_perm[0] = (S_ISDIR(perm)) ? 'd' : '-';
	str_perm[1] = (perm & S_IRUSR) ? 'r' : '-';
	str_perm[2] = (perm & S_IWUSR) ? 'w' : '-';
	str_perm[3] = (perm & S_IXUSR) ? 'x' : '-';
	str_perm[4] = (perm & S_IRGRP) ? 'r' : '-';
	str_perm[5] =  (perm & S_IWGRP) ? 'w' : '-';
	str_perm[6] = (perm & S_IXGRP) ? 'x' : '-';
	str_perm[7] = (perm & S_IROTH) ? 'r' : '-';
	str_perm[8] =  (perm & S_IWOTH) ? 'w' : '-';
	str_perm[9] = (perm & S_IXOTH) ? 'x' : '-';

	ft_putendl(str_perm);
}

bool		parse_dir(char *path, uint8_t const flags)
{
	CurrDir	*curr_dir;
	size_t	i;

	i = ~0ULL;
	NO_F(curr_dir = init_curr_dir(path, flags));
	IS_SET_BIT(flags, F_T_TIME) ? sort_time_stats(curr_dir->in_dir_objs,
							curr_dir->objs, IS_SET_BIT(flags, F_R_REV))
		: sort_ascii_dirents(curr_dir->in_dir_objs, curr_dir->objs,
			IS_SET_BIT(flags, F_R_REV));
	while (curr_dir->in_dir_objs > ++i)
		if (IS_SET_BIT(flags, F_L_LIST))
			s_print_long_format(&curr_dir->objs[i]);
		else
		{
			ft_printf("%s", curr_dir->objs[i].dirent->d_name);
			ft_putnchar(' ', curr_dir->max_obj_name_len
				- ft_strlen(curr_dir->objs[i].dirent->d_name));
			if (curr_dir->in_dir_objs - 1 != i)
				ft_putchar(' ');
		}
	ft_putchar('\n');
	if (IS_SET_BIT(flags, F_R_REC))
		s_check_dirs_recursive(curr_dir, flags, path);
	free_curr_dir(&curr_dir);
	return (true);
}
