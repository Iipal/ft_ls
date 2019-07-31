/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 16:15:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool		s_is_folder_hidden(struct dirent const *const dirent,
												uint8_t const flags)
{
	if (!IS_SET_BIT(flags, F_A_HDN))
		if (dirent->d_name[0] == '.')
			return (false);
	return (true);
}

static size_t	s_find_max_name_len(size_t const in_dir_objs,
								InDirObject const *const objs)
{
	size_t	curr_len;
	size_t	max_len;
	size_t	i;

	i = ~0ULL;
	max_len = ft_strlen((*objs).dirent->d_name);
	while (in_dir_objs > ++i)
	{
		curr_len = ft_strlen(objs[i].dirent->d_name);
		if (max_len < curr_len)
			max_len = curr_len;
	}
	return (max_len);
}

static CurrDir	*s_calc_in_dir_objs(char const *const path,
					uint8_t const flags)
{
	CurrDir			*out;
	struct dirent	*tmp_dirent;
	DIR				*tmp_dir;

	NODO_F(tmp_dir = opendir(path), perror(PERR));
	MEM(CurrDir, out, 1, E_ALLOC);
	while ((tmp_dirent = readdir(tmp_dir)))
		out->in_dir_objs += s_is_folder_hidden(tmp_dirent, flags);
	closedir(tmp_dir);
	MEM(InDirObject, out->objs, out->in_dir_objs, E_ALLOC);
	return (out);
}

CurrDir			*init_curr_dir(char const *const path,
					uint8_t const flags)
{
	CurrDir			*out;
	struct dirent	*tmp_dirent;
	DIR				*tmp_dir;
	struct stat		tmp_stat;
	size_t			i;

	i = ~0ULL;
	NO_F(out = s_calc_in_dir_objs(path, flags));
	NODO_F(tmp_dir = opendir(path), perror(PERR));
	while ((tmp_dirent = readdir(tmp_dir)))
	{
		stat(tmp_dirent->d_name, &tmp_stat);
		if (s_is_folder_hidden(tmp_dirent, flags))
		{
			NODOM_F(E_ALLOC_OBJ(OBJ_DIRENT),
			out->objs[++i].dirent = dup_dirent(tmp_dirent), free_curr_dir(&out));
			NODOM_F(E_ALLOC_OBJ(OBJ_STAT),
			out->objs[i].stat = dup_stat(&tmp_stat), free_curr_dir(&out));
		}
	}
	closedir(tmp_dir);
	out->max_obj_name_len
		= s_find_max_name_len(out->in_dir_objs, out->objs);
	return (out);
}
