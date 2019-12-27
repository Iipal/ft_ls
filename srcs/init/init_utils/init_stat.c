/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:05:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/28 01:27:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline bool
	init_stat(const char *restrict path,
		struct stat *restrict buff)
{
	struct stat	tmp_lstat;
	int			stat_ret;
	int			lstat_ret;

	stat_ret = stat(path, buff);
	lstat_ret = lstat(path, &tmp_lstat);
	LS_ASSERT_MGS(!(0 > stat_ret && 0 > lstat_ret), path);
	if (S_ISLNK(tmp_lstat.st_mode))
		*buff = tmp_lstat;
	return (true);
}

inline bool
	init_stat_no_err(const char *restrict path,
		struct stat *restrict buff)
{
	struct stat	tmp_lstat;
	int			stat_ret;
	int			lstat_ret;

	stat_ret = stat(path, buff);
	lstat_ret = lstat(path, &tmp_lstat);
	if (0 > stat_ret && 0 > lstat_ret)
		return (false);
	if (S_ISLNK(tmp_lstat.st_mode))
		*buff = tmp_lstat;
	return (true);
}
