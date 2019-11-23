/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:40:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 22:31:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	s_check_subdirs(const char *restrict prev_dir,
				const uint32_t n_objs,
				const struct s_object *restrict objs)
{
	char		*d_name;
	char		*subdir;
	uint32_t	i;

	i = ~0U;
	d_name = NULL;
	if (!(subdir = (char*)ft_memalloc(sizeof(char) * 1024)))
		return ((bool)ls_errno_msg(__FILE__,
						__PFUNC__, __LINE__, "ft_memalloc"));
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

void		output(const char *restrict path,
				const struct s_dir *restrict cd)
{
	if (!IS_BIT(g_flags, BIT_F_NOT_SORTED) && IS_BIT(g_flags, BIT_T_TIME))
		choose_sort(cd->objs, cd->n_objs,
			sizeof(struct s_object), sort_time_objects_cmp);
	else if (!IS_BIT(g_flags, BIT_F_NOT_SORTED))
		choose_sort(cd->objs, cd->n_objs,
			sizeof(struct s_object), sort_ascii_objects_cmp);
	if (IS_BIT(g_flags, BIT_L_LIST))
		plf(cd->n_objs, cd->objs);
	else
		pdf(cd->n_objs, cd->objs);
	if (IS_BIT(g_flags, BIT_R_RECURSIVE))
		s_check_subdirs(path, cd->n_objs, cd->objs);
}
