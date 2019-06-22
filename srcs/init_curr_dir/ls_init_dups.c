/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_dups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 22:59:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/22 03:44:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

struct dirent	*ls_dup_dirent(struct dirent *src)
{
	struct dirent	*out;

	MEM(struct dirent, out, 1, E_ALLOC);
	ft_memcpy(out, src, sizeof(struct dirent));
	return (out);
}

struct stat		*ls_dup_stat(struct stat *src)
{
	struct stat	*out;

	MEM(struct stat, out, 1, E_ALLOC);
	ft_memcpy(out, src, sizeof(struct stat));
	return (out);
}
