/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_dev_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:37:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 17:56:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline void
	s_catint(char *dst, int n)
{
	char	*tmp;

	tmp = ft_itoa(n);
	dst = ft_strcpy(dst, tmp);
	free(tmp);
}

inline char
	*plf_get_dev_info(char *dst, struct s_stat *restrict st)
{
	if (S_ISCHR(st->mode) || S_ISBLK(st->mode))
		ft_sprintf(dst, "%3d,%4d", major(st->rdev), minor(st->rdev));
	else
		s_catint(dst, st->size);
	return (dst);
}
