/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 22:59:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 22:30:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct dirent
	*dup_dirent(const struct dirent *restrict src)
{
	struct dirent	*out;

	if (!(out = ft_memalloc(sizeof(struct dirent))))
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "ft_memalloc"));
	*out = *src;
	return (out);
}

inline struct stat
	*dup_stat(const struct stat *restrict src)
{
	struct stat	*out;

	if (!(out = ft_memalloc(sizeof(struct stat))))
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "ft_memalloc"));
	*out = *src;
	return (out);
}
