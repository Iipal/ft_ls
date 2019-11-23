/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 15:16:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_stats_cmp(const void *a, const void *b)
{
	const struct s_object	*aa = (const struct s_object*)a;
	const struct s_object	*bb = (const struct s_object*)b;
	register t_time_t		cmp;

	if (IS_BIT(g_flags, BIT_U_ACCESS))
		cmp = aa->stat->st_atime - bb->stat->st_atime;
	else
		cmp = aa->stat->st_ctime - bb->stat->st_ctime;
	if (!cmp)
		return (sort_ascii_dirents_cmp(a, b));
	return (IS_BIT(g_flags, BIT_R_REVERSE) ? cmp : -cmp);
}
