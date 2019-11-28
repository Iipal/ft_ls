/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_dev_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:37:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 14:15:36 by tmaluh           ###   ########.fr       */
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
	*plf_get_dev_info(char *dst, struct stat *restrict st)
{
	if (S_ISCHR(st->st_mode))
		ft_sprintf(dst, "%3d,%4d", major(st->st_rdev), minor(st->st_rdev));
	else
		s_catint(dst, st->st_size);
	return (dst);
}
