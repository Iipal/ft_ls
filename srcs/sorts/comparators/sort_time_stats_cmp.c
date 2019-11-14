/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 16:22:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_stats_cmp(const void *a, const void *b)
{
	const t_time_t			a_mtime = ((InDirObject*)a)->stat->st_mtime;
	const t_time_t			b_mtime = ((InDirObject*)b)->stat->st_mtime;
	register const bool		is_rev = IS_BIT(g_flags, BIT_R_REVERSE);
	register t_time_t		cmp;

	cmp = a_mtime - b_mtime;
	if (!cmp)
		return (is_rev ? 1 : -1);
	return (is_rev ? (cmp) : -(cmp));
}
