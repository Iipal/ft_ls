/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/31 14:26:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_stats_cmp(void const *a, void const *b)
{
	int32_t const	cmp = ((InDirObject*)b)->stat->st_mtime
						- ((InDirObject*)a)->stat->st_mtime;

	return IS_BIT(g_flags, BIT_R_REVERSE) ? -cmp : cmp;
}
