/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 09:54:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static CurrDir	*s_precalc_in_dir_objs(DIR *dir)
{
	CurrDir			*out;
	struct dirent	*dirent;

	MEM(CurrDir, out, 1, E_ALLOC);
	while ((dirent = readdir(dir)))
		out->n_objs += !(!IS_BIT(g_flags, BIT_A_HIDDEN)
					&& '.' == dirent->d_name[0]);
	MEM(InDirObject, out->objs, out->n_objs, E_ALLOC);
	return (out);
}

CurrDir			*init_curr_dir(char *const path, bool const force_open_dir)
{
	CurrDir		*out;
	CurrDirInit	t;
	size_t		i;

	i = ~0ULL;
	IFR(!init_lstat_check_no_errno(path, &t.stat), NULL);
	if (!force_open_dir && !S_ISDIR(t.stat.st_mode))
		return (init_only_file(path));
	IFR(!(t.dir = opendir(path)), NULL);
	NO_F(out = s_precalc_in_dir_objs(t.dir));
	closedir(t.dir);
	t.dir = opendir(path);
	while ((t.dirent = readdir(t.dir)))
	{
		IFDOR(!init_lstat_check(plf_full_path(t.path, path,
			t.dirent->d_name, 1024UL), &t.stat), free_curr_dir(&out), NULL);
		if (!(!IS_BIT(g_flags, BIT_A_HIDDEN) && '.' == t.dirent->d_name[0]))
			if (!(t.curr = init_curr_in_dir_obj(&out->objs[++i],
								&t.stat, t.dirent)))
				return (free_curr_dir(&out));
	}
	closedir(t.dir);
	if (!out->n_objs)
		out = free_curr_dir(&out);
	return (out);
}
