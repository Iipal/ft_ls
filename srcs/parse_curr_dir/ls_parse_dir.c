/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:27:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 09:25:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

# define STR_SIZE sizeof("drwxrwxrwx")
# define FP_SPECIAL 1

static bool	add_check_dirs_recursive(CurrDir *curr_dir,
								const uint8_t fmask,
								string previous_path)
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
			ls_parse_dir(full_path, fmask);
		}
		ft_strdel(&full_path);
	}
	return (true);
}

static void	add_print_long_format(InDirObject *restrict const obj)
{
	static char		str[STR_SIZE];
	const mode_t	perm = obj->stat->st_mode;

	str[0] = (S_ISDIR(perm)) ? 'd' : '-';
	str[1] = (perm & S_IRUSR) ? 'r' : '-';
	str[2] = (perm & S_IWUSR) ? 'w' : '-';
	str[3] = (perm & S_IXUSR) ? 'x' : '-';
	str[4] = (perm & S_IRGRP) ? 'r' : '-';
	str[5] =  (perm & S_IWGRP) ? 'w' : '-';
	str[6] = (perm & S_IXGRP) ? 'x' : '-';
	str[7] = (perm & S_IROTH) ? 'r' : '-';
	str[8] =  (perm & S_IWOTH) ? 'w' : '-';
	str[9] = (perm & S_IXOTH) ? 'x' : '-';

	ft_putendl(str);
}

bool		ls_parse_dir(string path, const uint8_t fmask)
{
	CurrDir	*curr_dir;
	size_t	i;

	i = ~0ULL;
	NO_F(curr_dir = ls_init_curr_dir(path, fmask));
	IS_SET_BIT(fmask, F_T_TIME) ? ls_sort_stats_time(curr_dir->in_dir_objs,
							curr_dir->objs, IS_SET_BIT(fmask, F_R_REV))
		: ls_sort_dirents_ascii(curr_dir->in_dir_objs, curr_dir->objs,
			IS_SET_BIT(fmask, F_R_REV));
	while (curr_dir->in_dir_objs > ++i)
		if (IS_SET_BIT(fmask, F_L_LIST))
			add_print_long_format(&curr_dir->objs[i]);
		else
		{
			ft_printf("%s", curr_dir->objs[i].dirent->d_name);
			ft_putnchar(' ', curr_dir->max_obj_len
				- ft_strlen(curr_dir->objs[i].dirent->d_name));
			if (curr_dir->in_dir_objs - 1 != i)
				ft_putchar(' ');
		}
	ft_putchar('\n');
	if (IS_SET_BIT(fmask, F_R_REC))
		add_check_dirs_recursive(curr_dir, fmask, path);
	ls_free_curr_dir(&curr_dir);
	return (true);
}
