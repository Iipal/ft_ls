/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 22:59:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 18:22:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

struct dirent	*dup_dirent(const struct dirent *restrict src)
{
	struct dirent	*out;

	MEM(struct dirent, out, 1, E_ALLOC);
	*out = *src;
	return (out);
}

struct stat		*dup_stat(const struct stat *restrict src)
{
	struct stat	*out;

	MEM(struct stat, out, 1, E_ALLOC);
	*out = *src;
	return (out);
}
