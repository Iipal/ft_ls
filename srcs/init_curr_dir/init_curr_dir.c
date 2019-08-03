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

static CurrDir	*s_calc_in_dir_objs(char const *const path,
					uint8_t const flags)
{
	CurrDir			*out;
	struct dirent	*dirent;
	DIR				*dir;

	NODO_F(dir = opendir(path), perror(PERR));
	MEM(CurrDir, out, 1, E_ALLOC);
	while ((dirent = readdir(dir)))
		out->n_objs += !(!IS_BIT(flags, F_A_HDN) && '.' == dirent->d_name[0]);
	closedir(dir);
	MEM(InDirObject, out->objs, out->n_objs, E_ALLOC);
	return (out);
}

char	*s_full_path(char *const path, char *const dirent_name)
{
	char	*out;
	size_t	out_len;

	out = NULL;
	out_len = ft_strlen(path);
	if (path[out_len - 1] != '/')
		++out_len;
	out_len += ft_strlen(dirent_name);
	MEM(char, out, out_len + 1, E_ALLOC);
	ft_strcpy(out, path);
	if (out[ft_strlen(out)] != '/')
		out[ft_strlen(out)] = '/';
	ft_strcpy(out + ft_strlen(out), dirent_name);
	return (out);
}

CurrDir			*init_curr_dir(char *const path,
					uint8_t const flags)
{
	CurrDir			*out;
	struct dirent	*dirent;
	DIR				*dir;
	struct stat		*tmp_stat;
	size_t			i;

	i = ~0ULL;
	tmp_stat = &(struct stat){ 0 };
	NO_F(out = s_calc_in_dir_objs(path, flags));
	NODO_F(dir = opendir(path), perror(PERR));
	while ((dirent = readdir(dir)))
	{
		char	*full = s_full_path(path, dirent->d_name);
		stat(full, tmp_stat);
		free(full);
		if (!(!IS_BIT(flags, F_A_HDN) && '.' == dirent->d_name[0]))
		{
			NODOM_F(E_ALLOC_OBJ(OBJ_DIRENT),
			out->objs[++i].dirent = dup_dirent(dirent), free_curr_dir(&out));
			NODOM_F(E_ALLOC_OBJ(OBJ_STAT),
			out->objs[i].stat = dup_stat(tmp_stat), free_curr_dir(&out));
		}
	}
	closedir(dir);
	return (out);
}
