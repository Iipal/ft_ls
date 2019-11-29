/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_objects_cmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:30:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 13:02:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_size_objects_cmp(const void *a, const void *b)
{
	const off_t	a_size = ((const struct s_object*)a)->st->size;
	const off_t	b_size = ((const struct s_object*)b)->st->size;
	off_t		cmp;

	cmp = a_size - b_size;
	if (!cmp)
		return (sort_ascii_objects_cmp(a, b));
	return ((int32_t)(IS_BIT(g_flags, BIT_R_SORT_REV) ? cmp : -cmp));
}
