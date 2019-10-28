/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:27:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 22:12:44 by tmaluh           ###   ########.fr       */
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
	ft_strncpy(out + prev_path_len + is_no_slash, d_name, ft_strlen(d_name));
	return (out);
}

static bool	s_check_dirs_recursive(char *prev_path,
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
			parse_dir(new_path);
			ft_strdel(&new_path);
		}
	}
	return (true);
}

void		parse_flags_output(char *path, CurrDir *cd)
{
	if (!IS_BIT(g_flags, BIT_F_NOT_SORTED))
	{
		if (IS_BIT(g_flags, BIT_T_TIME))
			sort_time_stats(cd->n_objs, cd->objs);
		else
			sort_ascii_dirents(cd->n_objs, cd->objs);
	}
	if (IS_BIT(g_flags, BIT_L_LIST))
		plf_objs(cd->n_objs, cd->objs);
	else
		print_default_format(cd->n_objs, cd->objs);
	if (IS_BIT(g_flags, BIT_R_RECURSIVE))
		s_check_dirs_recursive(path, cd->n_objs, cd->objs);
}

bool		parse_dir(char *path)
{
	CurrDir	*cd;

	NO_F(cd = init_curr_dir(path, false));
	if (cd->is_file)
		parse_file(path, cd->objs);
	else
		parse_flags_output(path, cd);
	free_curr_dir(&cd);
	return (true);
}
