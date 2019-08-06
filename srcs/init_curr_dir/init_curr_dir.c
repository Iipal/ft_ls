/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 17:38:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static CurrDir	*s_precalc_in_dir_objs(uint8_t const flags, DIR *dir)
{
	CurrDir			*out;
	struct dirent	*dirent;

	MEM(CurrDir, out, 1, E_ALLOC);
	while ((dirent = readdir(dir)))
		out->n_objs += !(!IS_BIT(flags, F_A_HDN) && '.' == dirent->d_name[0]);
	MEM(InDirObject, out->objs, out->n_objs, E_ALLOC);
	return (out);
}

static char		*s_full_path(char *const dst,
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

static CurrDir	*s_only_file(char *const path)
{
	CurrDir 	*out;
	struct stat	st;
	int const	ret = stat(path, &st);

	IFDO_F(ret, perror(PERR));
	MEM(CurrDir, out, 1UL, E_ALLOC);
	out->n_objs = 1UL;
	MEM(InDirObject, out->objs, out->n_objs, E_ALLOC);
	MEM(struct stat, out->objs->stat, out->n_objs, E_ALLOC);
	out->is_file = true;
	*out->objs->stat = st;
	return (out);
}

CurrDir			*init_curr_dir(char *const path,
					uint8_t const flags)
{
	CurrDir		*out;
	CurrDirInit	tmp;
	size_t		i;

	i = ~0ULL;
	tmp.m_dir = opendir(path);
	if (!tmp.m_dir)
		return (s_only_file(path));
	NO_F(out = s_precalc_in_dir_objs(flags, tmp.m_dir));
	rewinddir(tmp.m_dir);
	while ((tmp.m_dirent = readdir(tmp.m_dir)))
	{
		stat(s_full_path(tmp.m_path, path, tmp.m_dirent->d_name), &tmp.m_stat);
		if (!(!IS_BIT(flags, F_A_HDN) && '.' == tmp.m_dirent->d_name[0]))
		{
			NODOM_F(E_ALLOC_OBJ(OBJ_DIRENT),
				out->objs[++i].dirent =
					dup_dirent(tmp.m_dirent), free_curr_dir(&out));
			NODOM_F(E_ALLOC_OBJ(OBJ_STAT),
				out->objs[i].stat = dup_stat(&tmp.m_stat), free_curr_dir(&out));
		}
	}
	closedir(tmp.m_dir);
	if (!out->n_objs)
		free_curr_dir(&out);
	return (out);
}
