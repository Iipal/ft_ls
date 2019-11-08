/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 23:09:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_stats_cmp(const void *a, const void *b)
{
	const t_time_t	a_mtime = ((InDirObject*)a)->stat->st_mtimespec.tv_sec;
	const t_time_t	b_mtime = ((InDirObject*)b)->stat->st_mtimespec.tv_sec;
	const t_time_t	a_nmtime = ((InDirObject*)a)->stat->st_mtimespec.tv_nsec;
	const t_time_t	b_nmtime = ((InDirObject*)b)->stat->st_mtimespec.tv_nsec;

	if (a_mtime == b_mtime)
		return (a_nmtime - b_nmtime);
	return (a_mtime - b_mtime);
}
