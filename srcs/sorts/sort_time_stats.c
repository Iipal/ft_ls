/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_stats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:29:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/30 11:23:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sort_time_stats(uint32_t const in_dir_objs,
						InDirObject *const objs)
{
	uint32_t	i;
	uint32_t	j;
	int64_t		cmp;
	bool const	is_reverse = IS_BIT(g_flags, BIT_R_REVERSE);

	if (!in_dir_objs || !objs)
		return ;
	i = ~0U;
	while ((in_dir_objs - 1) > ++i)
	{
		j = i;
		while (in_dir_objs > ++j)
		{
			cmp = objs[i].stat->st_mtime - objs[j].stat->st_mtime;
			if (is_reverse && 0L <= cmp)
				SWAP(objs[i], objs[j]);
			else if (!is_reverse && 0L > cmp)
				SWAP(objs[j], objs[i]);
		}
	}
}
