/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_curr_in_dir_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:54:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 12:55:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	*free_curr_in_dir_obj(InDirObject *obj)
{
	if (obj)
	{
		FREE(obj->dirent, free);
		FREE(obj->dirent, free);
	}
	return (NULL);
}
