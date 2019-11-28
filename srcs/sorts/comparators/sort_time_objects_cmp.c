/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_objects_cmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 15:33:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_objects_cmp(const void *a, const void *b)
{
	const struct s_object	*aa = (const struct s_object*)a;
	const struct s_object	*bb = (const struct s_object*)b;
	t_time_t				cmp;

	if (IS_BIT(g_flags, BIT_U_ACCESS))
		cmp = aa->stat->st_atime - bb->stat->st_atime;
	else
		cmp = aa->stat->st_ctime - bb->stat->st_ctime;
	if (!cmp)
		return (sort_ascii_objects_cmp(a, b));
	return ((int32_t)(IS_BIT(g_flags, BIT_R_SORT_REV) ? cmp : -cmp));
}
