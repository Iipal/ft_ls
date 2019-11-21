/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lstat_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:05:03 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 22:04:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

bool	init_lstat_check(const char *restrict path,
			struct stat *restrict buff)
{
	struct stat	tmp_lstat;

	if (0 > stat(path, buff))
	{
		ft_printf(ERR "%s[%s]: %s\n", __FILE__, __func__, strerror(errno));
		return (false);
	}
	if (0 > lstat(path, buff))
	{
		ft_printf(ERR "%s[%s]: %s\n", __FILE__, __func__, strerror(errno));
		return (false);
	}
	if (S_ISLNK(tmp_lstat.st_mode))
		*buff = tmp_lstat;
	return (true);
}

bool	init_lstat_check_no_errno(const char *restrict path,
			struct stat *restrict buff)
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
