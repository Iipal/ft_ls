/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_in_dir_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/12 15:16:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline InDirObject	*init_curr_in_dir_obj(InDirObject *restrict dst,
						const struct stat *restrict stat,
						const struct dirent *restrict dirent)
{
	InDirObject	*out;

	out = dst;
	if (!out)
		MEM(InDirObject, out, 1, E_ALLOC);
	if (dirent && !(out->dirent = dup_dirent(dirent)))
		return (free_curr_in_dir_obj(out));
	if (stat && !(out->stat = dup_stat(stat)))
		return (free_curr_in_dir_obj(out));
	out->d_name_len = 0UL;
	if (out->dirent)
		out->d_name_len = ft_strlen(out->dirent->d_name);
	return (out);
}
