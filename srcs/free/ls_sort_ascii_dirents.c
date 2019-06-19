/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_ascii_dirents.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/19 14:50:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_sort_ascii_dirents(const size_t in_dir_dirents, Dirent **dirents)
{
	Dirent	swap;
	size_t	i;
	size_t	j;

	if (!in_dir_dirents)
		return ;
	i = ~0ULL;
	while (in_dir_dirents > ++i && (!i ? (j = ~0ULL) : (j = i - 1)))
		while(in_dir_dirents > ++j)
			if (0 < ft_strcmp(dirents[i]->d_name, dirents[j]->d_name))
			{
				swap = *(dirents[i]);
				*(dirents[i]) = *(dirents[j]);
				*(dirents[j]) = swap;
			}
}
