/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 22:59:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/03 16:14:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

struct dirent	*dup_dirent(struct dirent const *const src)
{
	struct dirent	*out;

	MEM(struct dirent, out, 1, E_ALLOC);
	*out = *src;
	return (out);
}

struct stat		*dup_stat(struct stat const *const src)
{
	struct stat	*out;

	MEM(struct stat, out, 1, E_ALLOC);
	*out = *src;
	return (out);
}
