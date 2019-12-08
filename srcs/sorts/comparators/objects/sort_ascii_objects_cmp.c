/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_objects_cmp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 16:38:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int64_t	sort_ascii_objects_cmp(const void *a, const void *b)
{
	int64_t	cmp;

	cmp = (int64_t)ft_strcmp(((const struct s_object*)a)->d_name,
							((const struct s_object*)b)->d_name);
	return (IS_BIT(g_flags, BIT_R_SORT_REV) ? -cmp : cmp);
}
