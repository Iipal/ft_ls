/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_objects_cmp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 15:31:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_ascii_objects_cmp(const void *a, const void *b)
{
	int32_t	cmp;

	cmp = ft_strcmp(((const struct s_object*)a)->d_name,
					((const struct s_object*)b)->d_name);
	return (IS_BIT(g_flags, BIT_R_SORT_REV) ? -cmp : cmp);
}
