/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/20 12:58:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_sort_stats_time(const size_t in_dir_objs,
			InDirObject *const objs,
			const bool is_reverse)
{
	size_t		i;
	size_t		j;

	if (!in_dir_objs)
		return ;
	i = ~0ULL;
	while ((in_dir_objs - 1) > ++i && (!i ? !(j = i) : (j = i)))
		while(in_dir_objs > ++j)
			if (is_reverse)
			{
				if (objs[i].stat->st_mtime > objs[j].stat->st_mtime)
					SWAP(objs[i], objs[j]);
			}
			else
			{
				if (objs[i].stat->st_mtime < objs[j].stat->st_mtime)
					SWAP(objs[i], objs[j]);
			}
}

void	ls_sort_dirents_ascii(const size_t in_dir_objs,
			InDirObject *const objs,
			const bool is_reverse)
{
	size_t		i;
	size_t		j;

	if (!in_dir_objs)
		return ;
	i = ~0ULL;
	while ((in_dir_objs - 1) > ++i && (!i ? !(j = i) : (j = i)))
		while(in_dir_objs > ++j)
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
