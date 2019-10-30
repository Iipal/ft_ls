/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_dirents_cmp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:38:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/30 15:39:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_ascii_dirents_cmp(InDirObject const *a, InDirObject const *b)
{
	return (ft_strcmp(a->dirent->d_name, b->dirent->d_name));
}
