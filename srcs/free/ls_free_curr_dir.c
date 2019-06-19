/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free_curr_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/19 19:22:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_free_curr_dir(CurrDir **cur_dir)
{
	size_t	i;

	i = ~0ULL;
	if (*cur_dir)
	{
		while ((*cur_dir)->in_dir_objs > ++i)
		{
			FREE((*cur_dir)->objs[i].dirent, free);
			FREE((*cur_dir)->objs[i].stat, free);
		}
		FREE((*cur_dir)->objs, free);
		FREE((*cur_dir), free);
	}
}
