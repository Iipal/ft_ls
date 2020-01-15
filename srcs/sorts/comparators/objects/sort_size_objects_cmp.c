/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_objects_cmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:30:46 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 15:41:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int64_t	sort_size_objects_cmp(const void *restrict a, const void *restrict b)
{
	const off_t	a_size = ((const struct s_object*)a)->st->size;
	const off_t	b_size = ((const struct s_object*)b)->st->size;
	off_t		cmp;

	cmp = a_size - b_size;
	if (!cmp)
		return (sort_ascii_objects_cmp(a, b));
	return ((GDI_FLAGS_IS_BIT(BIT_R_SORT_REV) ? cmp : -cmp));
}
