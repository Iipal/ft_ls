/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 16:21:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sort_time_stats(uint32_t const in_dir_objs,
						InDirObject *const objs)
{
	register uint32_t	i;
	register uint32_t	j;
	register int64_t	cmp;

	if (!in_dir_objs || !objs)
		return ;
	i = ~0U;
	while ((in_dir_objs - 1) > ++i)
	{
		j = i;
		while (in_dir_objs > ++j)
		{
			cmp = objs[i].stat->st_mtime - objs[j].stat->st_mtime;
			if (IS_BIT(g_flags, BIT_R_REVERSE) && 0L < cmp)
				SWAP(objs[i], objs[j]);
			else if (0L > cmp)
				SWAP(objs[j], objs[i]);
		}
	}
}
