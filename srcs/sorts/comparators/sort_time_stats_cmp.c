/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/12 20:35:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_stats_cmp(const void *a, const void *b)
{
	const t_time_t	a_mtime = ((InDirObject*)a)->stat->st_mtimespec.tv_sec;
	const t_time_t	b_mtime = ((InDirObject*)b)->stat->st_mtimespec.tv_sec;
	const bool		is_rev = IS_BIT(g_flags, BIT_R_REVERSE);

	return (is_rev ? (a_mtime - b_mtime) : (b_mtime - a_mtime));
}
