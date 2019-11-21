/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_curr_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:38:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	*free_curr_dir(struct s_dir **curr_dir)
{
	int32_t	i;

	i = -1;
	if (*curr_dir)
	{
		if ((*curr_dir)->objs)
			while ((*curr_dir)->n_objs > ++i)
				free_curr_in_dir_obj(&(*curr_dir)->objs[i]);
		if ((*curr_dir)->objs)
			ft_memdel((void**)&(*curr_dir)->objs);
		ft_memdel((void**)curr_dir);
	}
	return (NULL);
}
