/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:27:47 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:22:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool
	s_check_subdirs(const char *restrict prev_dir,
		const int32_t n_objs,
		const struct s_object *restrict objs)
{
	char	*d_name;
	char	*subdir;
	int32_t	i;

	i = -1;
	d_name = NULL;
	subdir = (char[1024]) { 0 };
	while (n_objs > ++i)
	{
		d_name = objs[i].d_name;
		if (d_name && (('.' == d_name[0] && '\0' == d_name[1])
		|| ('.' == d_name[0] && '.' == d_name[1] && '\0' == d_name[2])
		|| !S_ISDIR(objs[i].st->mode)))
			continue ;
		u_full_path(subdir, prev_dir, d_name);
		ft_fprintf(stdout, "\n%s:\n", subdir);
		parse_dir(subdir);
	}
	return (true);
}

bool
	parse_dir(const char *restrict path)
{
	struct s_dir	*cd;

	ft_strcpy(GDI_SRC_GET_VALUE(), path);
	if (!(cd = init_dir(path, false)))
		return (false);
	if (cd->is_file)
		parse_file(path, cd->objs, true);
	else
	{
		output(cd);
		if (GDI_FLAGS_IS_BIT(BIT_R_RECURSIVE))
			s_check_subdirs(path, cd->n_objs, cd->objs);
	}
	free_dir(&cd);
	return (true);
}
