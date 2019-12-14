/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:27:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/12 18:52:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	s_check_subdirs(const char *restrict prev_dir,
				const int32_t n_objs,
				const struct s_object *restrict objs)
{
	char	*d_name;
	char	subdir[1024];
	int32_t	i;

	i = -1;
	d_name = NULL;
	ft_bzero(subdir, sizeof(char) * 1024);
	while (n_objs > ++i)
	{
		d_name = objs[i].d_name;
		if (d_name && (('.' == d_name[0] && '\0' == d_name[1])
		|| ('.' == d_name[0] && '.' == d_name[1] && '\0' == d_name[2])
		|| !S_ISDIR(objs[i].st->mode)))
			continue ;
		u_full_path(subdir, prev_dir, d_name);
		ft_strcpy(g_src_path, subdir);
		ft_fprintf(stdout, "\n%s:\n", subdir);
		parse_dir(subdir);
	}
	return (true);
}

inline bool	parse_dir(const char *restrict path)
{
	struct s_dir	*cd;

	ft_strcpy(g_src_path, path);
	if (!(cd = init_dir(path, false)))
		return (false);
	if (cd->is_file)
		parse_file(path, cd->objs, true);
	else
	{
		output(cd);
		if (IS_BIT(g_flags, BIT_R_RECURSIVE))
			s_check_subdirs(path, cd->n_objs, cd->objs);
	}
	free_dir(&cd);
	return (true);
}
