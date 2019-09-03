/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/03 12:52:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sort_time_stats(size_t const in_dir_objs,
						InDirObject *const objs)
{
	size_t	i;
	size_t	j;

	if (!in_dir_objs || !objs)
		return ;
	i = ~0ULL;
	while ((in_dir_objs - 1) > ++i)
	{
		j = i;
		while (in_dir_objs > ++j)
			if (IS_BIT(g_flags, F_R_REVERSE))
			{
				if (objs[i].stat->st_mtime >= objs[j].stat->st_mtime)
					SWAP(objs[i], objs[j]);
			}
			else
			{
				if (objs[i].stat->st_mtime <= objs[j].stat->st_mtime)
					SWAP(objs[j], objs[i]);
			}
	}
}
