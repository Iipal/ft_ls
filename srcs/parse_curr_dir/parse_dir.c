/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:27:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 17:37:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static char	*s_get_new_path(char const *const prev_path,
							char const *const d_name)
{
	size_t const	prev_path_len = ft_strlen(prev_path);
	bool const		is_no_slash = '/' != prev_path[prev_path_len - 1];
	char			*out;

	out = ft_strnew(ft_strlen(d_name) + prev_path_len + is_no_slash);
	out = ft_strncpy(out, prev_path, prev_path_len);
	if (is_no_slash)
		out[prev_path_len] = '/';
	ft_strncpy(out + prev_path_len + 1, d_name, ft_strlen(d_name));
	return (out);
}

static bool	s_check_dirs_recursive(uint8_t const flags,
								char *prev_path,
								size_t const n_objs,
								InDirObject const *const objs)
{
	char	*new_path;
	size_t	i;

	i = ~0ULL;
	new_path = NULL;
	while (n_objs > ++i)
	{
		if ('.' == objs[i].dirent->d_name[ft_strlen(objs[i].dirent->d_name) - 1]
		|| !ft_strcmp(objs[i].dirent->d_name
			+ (ft_strlen(objs[i].dirent->d_name) - 2), ".."))
			continue ;
		if (S_ISDIR(objs[i].stat->st_mode))
		{
			new_path = s_get_new_path(prev_path, objs[i].dirent->d_name);
			ft_printf("\n%s:\n", new_path);
			parse_dir(new_path, flags);
			ft_strdel(&new_path);
		}
	}
	return (true);
}

bool		parse_dir(char *path, uint8_t const flags)
{
	CurrDir	*cd;

	NO_F(cd = init_curr_dir(path, flags));
	if (cd->is_file)
	{
		parse_file(path, flags, cd->objs->stat);
	}
	else
	{
		if (IS_BIT(flags, F_T_TIME))
			sort_time_stats(cd->n_objs, cd->objs, IS_BIT(flags, F_R_REV));
		else
			sort_ascii_dirents(cd->n_objs, cd->objs, IS_BIT(flags, F_R_REV));
		if (IS_BIT(flags, F_L_LIST))
			print_long_format(cd->n_objs, cd->objs);
		else
			print_default_format(cd->n_objs, cd->objs);
		if (IS_BIT(flags, F_R_REC))
			s_check_dirs_recursive(flags, path, cd->n_objs, cd->objs);
	}
	free_curr_dir(&cd);
	return (true);
}
