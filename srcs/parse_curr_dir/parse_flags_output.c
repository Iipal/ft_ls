/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:40:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/11 23:40:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	s_check_subdirs(const char *restrict prev_dir,
				const uint32_t n_objs,
				const InDirObject *restrict objs)
{
	char		*d_name;
	char		*subdir;
	uint32_t	i;

	i = ~0U;
	d_name = NULL;
	subdir = (char*)ft_memalloc(sizeof(char) * 256);
	while (n_objs > ++i)
	{
		d_name = objs[i].dirent->d_name;
		if (('.' == d_name[0] && '\0' == d_name[1])
		|| ('.' == d_name[0] && '.' == d_name[1] && '\0' == d_name[2])
		|| !S_ISDIR(objs[i].stat->st_mode))
			continue ;
		subdir = u_full_path(subdir, prev_dir, d_name);
		ft_printf("\n%s:\n", subdir);
		parse_dir(subdir);
	}
	ft_strdel(&subdir);
	return (true);
}

void		parse_flags_output(const char *restrict path,
				const CurrDir *restrict cd)
{
	if (!IS_BIT(g_flags, BIT_F_NOT_SORTED))
	{
		if (IS_BIT(g_flags, BIT_T_TIME))
			isort(cd->objs, cd->n_objs, sizeof(InDirObject),
				sort_time_stats_cmp);
		else
			isort(cd->objs, cd->n_objs, sizeof(InDirObject),
				sort_ascii_dirents_cmp);
	}
	if (IS_BIT(g_flags, BIT_L_LIST))
		plf_objs(cd->n_objs, cd->objs);
	else
		pdf_objs(cd->n_objs, cd->objs);
	if (IS_BIT(g_flags, BIT_R_RECURSIVE))
		s_check_subdirs(path, cd->n_objs, cd->objs);
}
