/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_objects_cmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 15:42:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int64_t	sort_time_objects_cmp(const void *restrict a, const void *restrict b)
{
	const struct s_stat	*st_a = ((const struct s_object*)a)->st;
	const struct s_stat	*st_b = ((const struct s_object*)b)->st;
	t_time_t			cmp;

	if (GDI_FLAGS_IS_BIT(BIT_U_ACCESS))
		cmp = st_a->a_time - st_b->a_time;
	else
		cmp = st_a->m_time - st_b->m_time;
	if (!cmp)
		return (sort_ascii_objects_cmp(a, b));
	return ((GDI_FLAGS_IS_BIT(BIT_R_SORT_REV) ? cmp : -cmp));
}
