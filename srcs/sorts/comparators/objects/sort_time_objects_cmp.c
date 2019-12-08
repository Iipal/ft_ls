/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_objects_cmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 17:14:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int64_t	sort_time_objects_cmp(const void *restrict a, const void *restrict b)
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
	return ((IS_BIT(g_flags, BIT_R_SORT_REV) ? cmp : -cmp));
}
