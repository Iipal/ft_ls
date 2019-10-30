/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_curr_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/30 15:05:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	*free_curr_dir(CurrDir **curr_dir)
{
	int32_t	i;

	i = -1;
	if (*curr_dir)
	{
		while ((*curr_dir)->n_objs > ++i)
		{
			FREE((*curr_dir)->objs[i].dirent, free);
			FREE((*curr_dir)->objs[i].stat, free);
		}
		FREE((*curr_dir)->objs, free);
		FREE((*curr_dir), free);
	}
	return (NULL);
}
