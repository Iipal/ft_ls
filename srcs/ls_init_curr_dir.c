/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_curr_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/20 09:18:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline struct dirent	__attribute__((always_inline)) *add_dup_dirent(
	struct dirent *src)
{
	struct dirent	*out;

	MEM(struct dirent, out, 1, E_ALLOC);
	*out = *src;
	return (out);
}

static inline struct stat 	__attribute__((always_inline)) *add_dup_stat(
	struct stat *src)
{
	struct stat	*out;

	MEM(struct stat, out, 1, E_ALLOC);
	*out = *src;
	return (out);
}

static inline bool	__attribute__((always_inline)) add_check_exist_flags(
	const struct dirent *const dirent,
	const Flags *const flags)
{
	if (!flags->f_a_show_hidden
	&& !ft_strncmp((string)dirent->d_name, ".", ft_strlen(".")))
		return (false);
	return (true);
}

CurrDir	*ls_init_curr_dir(string path, const Flags *const flags)
{
	struct dirent	*tmp_dirent;
	CurrDir			*out;
	DIR				*tmp_dir;
	size_t			i;
	struct stat		tmp_stat;

	NODO_F(tmp_dir = opendir(path), perror(PERR));
	MEM(CurrDir, out, 1, E_ALLOC);
	while ((tmp_dirent = readdir(tmp_dir)))
		out->in_dir_objs += add_check_exist_flags(tmp_dirent, flags);
	closedir(tmp_dir);
	MEM(InDirObject, out->objs, out->in_dir_objs, E_ALLOC);
	NODO_F(tmp_dir = opendir(path), perror(PERR));
	i = ~0ULL;
	while ((tmp_dirent = readdir(tmp_dir)))
	{
		if (stat(tmp_dirent->d_name, &tmp_stat))
			perror(tmp_dirent->d_name);
		if (add_check_exist_flags(tmp_dirent, flags))
		{
			NODOM_F(E_ALLOC, out->objs[++i].dirent = add_dup_dirent(tmp_dirent),
				ls_free_curr_dir(&out));
			NODOM_F(E_ALLOC, out->objs[i].stat = add_dup_stat(&tmp_stat),
				ls_free_curr_dir(&out));
		}
	}
	closedir(tmp_dir);
	return (out);
}
