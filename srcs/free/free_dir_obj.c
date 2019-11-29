/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:54:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:43:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	*free_dir_obj(struct s_object *obj)
{
	if (obj)
	{
		if (obj->st)
			free(obj->st);
		if (obj->d_name)
			ft_strdel(&obj->d_name);
		if (obj->clr_name)
			ft_strdel(&obj->clr_name);
	}
	return (NULL);
}
