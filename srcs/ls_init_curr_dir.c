/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_curr_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/19 11:37:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline Dirent	__attribute__((always_inline)) *add_dup_dirent(
	Dirent *src)
{
	Dirent	*out;

	MEM(Dirent, out, 1, E_ALLOC);
	*out = *src;
	return (out);
}

static inline bool	__attribute__((always_inline)) add_check_exist_flags(
	const Dirent *const dirent,
	const Flags *const flags)
{
	if (!flags->f_a_show_hidden
	&& !ft_strncmp((string)dirent->d_name, ".", ft_strlen(".")))
		return (false);
	return (true);
}

CurrDir	*ls_init_curr_dir(string path, const Flags *const flags)
{
	Dirent	*tmp_dirent;
	CurrDir	*out;
	DIR		*tmp_dir;
	size_t	i;

	NODO_F(tmp_dir = opendir(path), perror(PERR));
	MEM(CurrDir, out, 1, E_ALLOC);
	while ((tmp_dirent = readdir(tmp_dir)))
		out->in_dir_dirents += add_check_exist_flags(tmp_dirent, flags);
	closedir(tmp_dir);
	MEM(Dirent*, out->dirents, out->in_dir_dirents, E_ALLOC);
	NODO_F(tmp_dir = opendir(path), perror(PERR));
	i = ~0ULL;
	while ((tmp_dirent = readdir(tmp_dir)))
		if (add_check_exist_flags(tmp_dirent, flags))
			NODOM_F(E_ALLOC, out->dirents[++i] = add_dup_dirent(tmp_dirent),
				ls_free_curr_dir(&out));
	closedir(tmp_dir);
	return (out);
}
