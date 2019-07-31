/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_curr_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 09:25:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool		add_check_exist_flags(const struct dirent *const dirent,
												uint8_t const fmask)
{
	if (!IS_SET_BIT(fmask, F_A_HDN)
	&& !ft_strncmp((string)dirent->d_name, ".", ft_strlen(".")))
		return (false);
	return (true);
}

static size_t	add_find_max_len(size_t in_dir_objs, size_t *objs_name_lens)
{
	size_t	max_len;

	max_len = objs_name_lens[in_dir_objs - 1];
	while (in_dir_objs--)
		if (max_len < objs_name_lens[in_dir_objs])
			max_len = objs_name_lens[in_dir_objs];
	return (max_len);
}

static CurrDir	*pre_calc_curr_dir(string path, uint8_t const fmask)
{
	CurrDir			*out;
	struct dirent	*tmp_dirent;
	DIR				*tmp_dir;

	NODO_F(tmp_dir = opendir(path), perror(PERR));
	MEM(CurrDir, out, 1, E_ALLOC);
	while ((tmp_dirent = readdir(tmp_dir)))
		out->in_dir_objs += add_check_exist_flags(tmp_dirent, fmask);
	closedir(tmp_dir);
	MEM(InDirObject, out->objs, out->in_dir_objs, E_ALLOC);
	MEM(size_t, out->obj_name_lens, out->in_dir_objs, E_ALLOC);
	return (out);
}

CurrDir			*ls_init_curr_dir(string path, uint8_t const fmask)
{
	CurrDir			*out;
	struct dirent	*tmp_dirent;
	DIR				*tmp_dir;
	struct stat		tmp_stat;
	size_t			i;

	i = ~0ULL;
	NO_F(out = pre_calc_curr_dir(path, fmask));
	NODO_F(tmp_dir = opendir(path), perror(PERR));
	while ((tmp_dirent = readdir(tmp_dir)))
	{
		stat(tmp_dirent->d_name, &tmp_stat);
		if (add_check_exist_flags(tmp_dirent, fmask))
		{
			NODOM_F(E_ALLOC, out->objs[++i].dirent = ls_dup_dirent(tmp_dirent),
				ls_free_curr_dir(&out));
			NODOM_F(E_ALLOC, out->objs[i].stat = ls_dup_stat(&tmp_stat),
				ls_free_curr_dir(&out));
			out->obj_name_lens[i] = ft_strlen(out->objs[i].dirent->d_name);
		}
	}
	closedir(tmp_dir);
	out->max_obj_len = add_find_max_len(out->in_dir_objs, out->obj_name_lens);
	return (out);
}
