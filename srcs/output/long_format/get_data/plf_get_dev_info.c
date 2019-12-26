/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_dev_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:37:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/26 01:13:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*plf_get_dev_info(char *dst, struct s_stat *restrict st)
{
	char	*temp;

	if (S_ISCHR(st->mode) || S_ISBLK(st->mode))
		ft_sprintf(dst, "%3d,%4d", major(st->rdev), minor(st->rdev));
	else
	{
		temp = ft_ltoa(st->size);
		dst = ft_strcpy(dst, temp);
		free(temp);
	}
	return (dst);
}
