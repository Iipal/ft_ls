/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_dirents_cmp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 18:15:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_ascii_dirents_cmp(const void *a, const void *b)
{
	int32_t const	cmp = ft_strcmp(((InDirObject*)a)->dirent->d_name,
									((InDirObject*)b)->dirent->d_name);

	return (IS_BIT(g_flags, BIT_R_REVERSE) ? -cmp : cmp);
}
