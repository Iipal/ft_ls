/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 11:38:49 by tmaluh           ###   ########.fr       */
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

static char		*s_under_path(char *const dst,
							char *const path,
							char *const dirent_name)
{
	ft_bzero(dst, sizeof(char) * 1024);
	ft_strcpy(dst, path);
	if (dst[ft_strlen(dst)] != '/')
		dst[ft_strlen(dst)] = '/';
	ft_strcpy(dst + ft_strlen(dst), dirent_name);
	return (dst);
}

static bool		s_check_lstat(char *const path, struct stat *buff)
{
	struct stat	tmp_lstat;

	IFDO_F(0 > stat(path, buff), perror("stat"));
	IFDO_F(0 > lstat(path, buff), perror("lstat"));
	if (S_ISLNK(tmp_lstat.st_mode))
		*buff = tmp_lstat;
	return (true);
}

static CurrDir	*s_only_file(char *const path)
{
	CurrDir		*out;
	struct stat	st;

	if (!s_check_lstat(path, &st))
		return (NULL);
	MEM(CurrDir, out, 1UL, E_ALLOC);
	out->n_objs = 1UL;
	out->is_file = true;
	out->objs = init_curr_in_dir_obj(NULL, &st, NULL);
	if (!out->objs)
		out = free_curr_dir(&out);
	return (out);
}

CurrDir			*init_curr_dir(char *const path)
{
	CurrDir		*out;
	InDirObject	*c;
	CurrDirInit	t;
	size_t		i;

	i = ~0ULL;
	if (!(t.dir = opendir(path)))
		return (s_only_file(path));
	NO_F(out = s_precalc_in_dir_objs(t.dir));
	rewinddir(t.dir);
	while ((t.dirent = readdir(t.dir)))
	{
		IFDOR(!s_check_lstat(s_under_path(t.path, path,
			t.dirent->d_name), &t.stat), free_curr_dir(&out), NULL);
		if (!(!IS_BIT(g_flags, BIT_A_HIDDEN) && '.' == t.dirent->d_name[0]))
			if (!(c = init_curr_in_dir_obj(&out->objs[++i], &t.stat, t.dirent)))
				return (free_curr_dir(&out));
	}
	closedir(t.dir);
	if (!out->n_objs)
		out = free_curr_dir(&out);
	return (out);
}
