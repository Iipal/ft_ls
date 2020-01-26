/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:05:03 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/25 23:43:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline bool	init_stat(const char *restrict path,
					struct stat *restrict buff)
{
	struct stat	tmp_lstat;

	LS_ASSERT_MGS(!(0 > stat(path, buff) && 0 > lstat(path, &tmp_lstat)), path);
	if (S_ISLNK(tmp_lstat.st_mode))
		*buff = tmp_lstat;
	return (true);
}

inline bool	init_stat_no_err(const char *restrict path,
							struct stat *restrict buff)
{
	struct stat	tmp_lstat;

	if (0 > stat(path, buff) && 0 > lstat(path, &tmp_lstat))
		return (false);
	if (S_ISLNK(tmp_lstat.st_mode))
		*buff = tmp_lstat;
	return (true);
}
