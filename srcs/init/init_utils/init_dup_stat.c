/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dup_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 22:59:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/28 01:31:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct s_stat
	*dup_stat(const struct stat *restrict src)
{
	struct s_stat	*out;

	LS_ASSERT(out = ft_memalloc(sizeof(*out)));
	*out = (struct s_stat){ src->st_uid, src->st_gid,
		src->st_atime, src->st_ctime, src->st_mtime,
		src->st_size, src->st_blocks, src->st_rdev,
		src->st_mode, src->st_nlink };
	return (out);
}
