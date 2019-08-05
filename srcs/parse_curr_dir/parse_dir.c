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

static bool	s_check_dirs_recursive(uint8_t const flags, char *previous_path,
						size_t const n_objs, InDirObject const *const objs)
{
	DIR		*tmp_dir;
	char	*full_path;
	size_t	i;

	i = ~0ULL;
	full_path = NULL;
	while (n_objs > ++i)
	{
		if ('/' != previous_path[ft_strlen(previous_path) - 1])
		{
			full_path = ft_strnew(sizeof(char)
				* (ft_strlen(objs[i].dirent->d_name)
				+ ft_strlen(previous_path) + 1));
			full_path = ft_strncpy(full_path, previous_path,
									ft_strlen(previous_path));
			full_path[ft_strlen(previous_path)] = '/';
			full_path = ft_strncat(full_path, objs[i].dirent->d_name,
								ft_strlen(objs[i].dirent->d_name));
		}
		else
			full_path =
				ft_strjoin(previous_path, objs[i].dirent->d_name);
		if (*(full_path + (ft_strlen(full_path) - 1)) == '.'
		|| !ft_strcmp(full_path + (ft_strlen(full_path) - 2), ".."))
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

bool		parse_dir(char *path, uint8_t const flags)
{
	CurrDir	*cd;

	NO_F(cd = init_curr_dir(path, flags));
	if (IS_BIT(flags, F_T_TIME))
		sort_time_stats(cd->n_objs, cd->objs, IS_BIT(flags, F_R_REV));
	else
		sort_ascii_dirents(cd->n_objs, cd->objs, IS_BIT(flags, F_R_REV));
	if (IS_BIT(flags, F_L_LIST))
		print_long_format(cd->n_objs, cd->objs, flags);
	else
		print_default_format(cd->n_objs, cd->objs);
	if (IS_BIT(flags, F_R_REC))
		s_check_dirs_recursive(flags, path, cd->n_objs, cd->objs);
	free_curr_dir(&cd);
	return (true);
}
