/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_curr_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/12 00:09:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	*free_curr_dir(CurrDir **curr_dir)
{
	int32_t	i;

	i = -1;
	if (*curr_dir)
	{
		if ((*curr_dir)->objs)
			while ((*curr_dir)->n_objs > ++i)
				free_curr_in_dir_obj(&(*curr_dir)->objs[i]);
		FREE((*curr_dir)->objs, free);
		FREE((*curr_dir), free);
	}
	return (NULL);
}
