/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_objects_cmp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 21:20:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_ascii_objects_cmp(const void *a, const void *b)
{
	const char		*a_str = ((const struct s_object*)a)->d_name;
	const char		*b_str = ((const struct s_object*)b)->d_name;
	const size_t	a_len = ((const struct s_object*)a)->d_name_len;
	int32_t			cmp;

	cmp = ft_strncmp(a, b, a_len);
	return (IS_BIT(g_flags, BIT_R_SORT_REV) ? -cmp : cmp);
}
