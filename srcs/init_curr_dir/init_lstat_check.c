/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lstat_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:05:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 17:45:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

bool	init_lstat_check(char *const path, struct stat *buff)
{
	struct stat	tmp_lstat;

	IFDO_F(0 > stat(path, buff), DEF_STRERR("ls", path));
	IFDO_F(0 > lstat(path, &tmp_lstat), DEF_STRERR("ls", path));
	if (S_ISLNK(tmp_lstat.st_mode))
		*buff = tmp_lstat;
	return (true);
}

bool	init_lstat_check_no_errno(char *const path, struct stat *buff)
{
	struct stat	tmp_lstat;

	if (0 > stat(path, buff))
		return (false);
	if (0 > lstat(path, &tmp_lstat))
		return (false);
	if (S_ISLNK(tmp_lstat.st_mode))
		*buff = tmp_lstat;
	return (true);
}
