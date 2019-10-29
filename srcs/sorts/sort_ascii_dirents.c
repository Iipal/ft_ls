/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_dirents.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 16:29:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sort_ascii_dirents(uint32_t const in_dir_objs,
							InDirObject *const objs)
{
	register uint32_t	i;
	register uint32_t	j;
	register int32_t	cmp;

	if (!in_dir_objs || 1U == in_dir_objs || !objs)
		return ;
	i = ~0U;
	while (in_dir_objs - 1U > ++i)
	{
		j = i;
		while (in_dir_objs > ++j)
		{
			cmp = ft_strcmp(objs[i].dirent->d_name, objs[j].dirent->d_name);
			if (IS_BIT(g_flags, BIT_R_REVERSE) && 0 > cmp)
				SWAP(objs[i], objs[j]);
			else if (0 < cmp)
				SWAP(objs[j], objs[i]);
		}
	}
}
