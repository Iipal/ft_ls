/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/19 21:04:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_sort_stats_time(const size_t in_dir_objs, InDirObject *objs)
{
	InDirObject	swap;
	size_t		i;
	size_t		j;

	i = ~0ULL;
	while (in_dir_objs > ++i)
	{
		j = !i ? ~0ULL : i - 1;
		printf("%ld\n", objs[i].stat->st_mtime);
		while(in_dir_objs > ++j)
			if (objs[i].stat->st_mtime < objs[j].stat->st_mtime)
			{
				swap = objs[i];
				objs[i] = objs[j];
				objs[j] = swap;
			}
	}
}

void	ls_sort_dirents_ascii(const size_t in_dir_objs, InDirObject *objs)
{
	InDirObject	swap;
	string		tmp_i;
	string		tmp_j;
	size_t		i;
	size_t		j;

	if (!in_dir_objs)
		return ;
	i = ~0ULL;
	while (in_dir_objs > ++i)
	{
		j = !i ? ~0ULL : i - 1;
		printf("%s\n", objs[i].dirent->d_name);
		while(in_dir_objs > ++j)
		{
			tmp_i = ft_strdup(objs[i].dirent->d_name);
			tmp_j = ft_strdup(objs[j].dirent->d_name);
			if (0 > ft_strcmp(ft_strlwr(tmp_i), ft_strlwr(tmp_j)))
			{
				swap = objs[i];
				objs[i] = objs[j];
				objs[j] = swap;
			}
			ft_strdel(&tmp_i);
			ft_strdel(&tmp_j);
		}
	}
}
