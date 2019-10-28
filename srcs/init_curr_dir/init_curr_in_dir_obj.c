/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_curr_in_dir_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 12:51:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline InDirObject	*init_curr_in_dir_obj(InDirObject *dst,
										struct stat *stat,
										struct dirent *dirent)
{
	InDirObject	*out;

	out = dst;
	if (!out)
		MEM(InDirObject, out, 1, E_ALLOC);
	if (stat && !(out->dirent = dup_dirent(dirent)))
		return (free_curr_in_dir_obj(out));
	if (dirent && !(out->stat = dup_stat(stat)))
		return (free_curr_in_dir_obj(out));
	return (out);
}
