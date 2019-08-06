/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_dirents.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 17:23:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sort_ascii_dirents(size_t const in_dir_objs,
							InDirObject *const objs,
							bool const is_reverse)
{
	size_t	i;
	size_t	j;

	if (!in_dir_objs || 1UL == in_dir_objs || !objs)
		return ;
	i = ~0ULL;
	while (in_dir_objs - 1UL > ++i)
	{
		j = i;
		while (in_dir_objs > ++j)
			if (is_reverse)
			{
				if (0 > ft_strcmp(objs[i].dirent->d_name,
						objs[j].dirent->d_name))
					SWAP(objs[i], objs[j]);
			}
			else
			{
				if (0 < ft_strcmp(objs[i].dirent->d_name,
						objs[j].dirent->d_name))
					SWAP(objs[i], objs[j]);
			}
	}
}
