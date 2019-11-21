/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:39:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_stats_cmp(const void *a, const void *b)
{
	const t_time_t			a_mtime = ((struct s_object*)a)->stat->st_mtime;
	const t_time_t			b_mtime = ((struct s_object*)b)->stat->st_mtime;
	register const bool		is_rev = IS_BIT(g_flags, BIT_R_REVERSE);
	register t_time_t		cmp;

	cmp = a_mtime - b_mtime;
	if (!cmp)
		return (sort_ascii_dirents_cmp(a, b));
	return (is_rev ? (cmp) : -(cmp));
}
