/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dup_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 22:59:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 14:26:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct s_stat
	*dup_stat(const struct stat *restrict src)
{
	struct s_stat	*out;

	if (!(out = ft_memalloc(sizeof(*out))))
		return (ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc"));
	*out = (struct s_stat){ src->st_uid, src->st_gid,
		src->st_atimespec.tv_sec,
		src->st_ctimespec.tv_sec,
		src->st_mtimespec.tv_sec,
		src->st_size, src->st_blocks, src->st_rdev,
		src->st_mode, src->st_nlink };
	return (out);
}
