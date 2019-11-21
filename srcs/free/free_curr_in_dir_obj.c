/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_curr_in_dir_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:54:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:39:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	*free_curr_in_dir_obj(struct s_object *obj)
{
	if (obj)
	{
		if (obj->dirent)
			ft_memdel((void**)&obj->dirent);
		if (obj->stat)
			ft_memdel((void**)&obj->stat);
	}
	return (NULL);
}
