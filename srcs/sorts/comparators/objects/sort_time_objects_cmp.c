/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_objects_cmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 18:37:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_time_objects_cmp(const void *a, const void *b)
{
	const struct s_stat	*st_a = ((const struct s_object*)a)->st;
	const struct s_stat	*st_b = ((const struct s_object*)b)->st;
	t_time_t			cmp;

	if (IS_BIT(g_flags, BIT_U_ACCESS))
		cmp = st_a->a_time - st_b->a_time;
	else
		cmp = st_a->m_time - st_b->m_time;
	if (!cmp)
		return (sort_ascii_objects_cmp(a, b));
	return ((int32_t)(IS_BIT(g_flags, BIT_R_SORT_REV) ? cmp : -cmp));
}
