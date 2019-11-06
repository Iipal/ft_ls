/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 18:07:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_stats_cmp(const void *a, const void *b)
{
	const int32_t	cmp = ((InDirObject*)a)->stat->st_mtime
						- ((InDirObject*)b)->stat->st_mtime;

	return (IS_BIT(g_flags, BIT_R_REVERSE) ? cmp : -cmp);
}
