/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/20 17:58:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static CurrDir	*s_precalc_in_dir_objs(DIR *restrict dir)
{
	CurrDir			*out;
	struct dirent	*dirent;
	int32_t			total_n_objs;

	total_n_objs = 0;
	MEM(CurrDir, out, 1, E_ALLOC);
	while ((dirent = readdir(dir)))
	{
		out->n_objs += !(!IS_BIT(g_flags, BIT_A_HIDDEN)
					&& '.' == dirent->d_name[0]);
		++total_n_objs;
	}
	if (total_n_objs && !out->n_objs)
		total_n_objs = 1;
	MEM(InDirObject, out->objs, total_n_objs, E_ALLOC);
	rewinddir(dir);
	return (out);
}

CurrDir			*init_curr_dir(const char *path,
					const bool force_open_dir)
{
	CurrDir				*out;
	CurrDirInit			t;
	register uint32_t	i;

	i = ~0U;
	IFR(!init_lstat_check_no_errno(path, &t.stat), NULL);
	if (!force_open_dir && !S_ISDIR(t.stat.st_mode))
		return (init_only_file(path));
	IFR(!(t.dir = opendir(path)), NULL);
	NO_F(out = s_precalc_in_dir_objs(t.dir));
	MEM(char, t.tmp, 256, E_ALLOC);
	while ((t.dirent = readdir(t.dir)))
		if (!(!IS_BIT(g_flags, BIT_A_HIDDEN) && '.' == t.dirent->d_name[0]))
		{
			IFDOR(!init_lstat_check(u_full_path(t.tmp, path, t.dirent->d_name),
				&t.stat), free_curr_dir(&out), NULL);
			if (!(t.curr = init_curr_in_dir_obj(&out->objs[++i],
					&t.stat, t.dirent)))
				return (free_curr_dir(&out));
		}
	closedir(t.dir);
	FREE(t.tmp, free);
	if (!out->n_objs)
		out = free_curr_dir(&out);
	return (out);
}
