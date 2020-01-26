/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:50:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	*free_dir(struct s_dir **curr_dir)
{
	size_t	i;

	i = ~0UL;
	if (*curr_dir)
	{
		if ((*curr_dir)->objs)
			while ((*curr_dir)->n_objs > ++i)
				free_dir_obj(&(*curr_dir)->objs[i]);
		if ((*curr_dir)->objs)
			ft_memdel((void**)&(*curr_dir)->objs);
		ft_memdel((void**)curr_dir);
	}
	return (NULL);
}
