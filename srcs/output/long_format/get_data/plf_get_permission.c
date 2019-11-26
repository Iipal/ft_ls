/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_permission.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:23:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/26 16:57:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline char __attribute__((__const__))
	s_get_type(const mode_t st_mode_perm)
{
	if (S_ISDIR(st_mode_perm))
		return ('d');
	else if (S_ISCHR(st_mode_perm))
		return ('c');
	else if (S_ISBLK(st_mode_perm))
		return ('b');
	else if (S_ISLNK(st_mode_perm))
		return ('l');
	else if (S_ISFIFO(st_mode_perm))
		return ('p');
	else if (S_ISSOCK(st_mode_perm))
		return ('s');
	return ('-');
}

inline char
	*plf_get_permission(char *restrict perm_str, const mode_t st_mode_perm)
{
	perm_str[0] = s_get_type(st_mode_perm);
	perm_str[1] = (st_mode_perm & S_IRUSR) ? 'r' : '-';
	perm_str[2] = (st_mode_perm & S_IWUSR) ? 'w' : '-';
	perm_str[3] = (st_mode_perm & S_IXUSR) ? 'x' : '-';
	perm_str[4] = (st_mode_perm & S_IRGRP) ? 'r' : '-';
	perm_str[5] = (st_mode_perm & S_IWGRP) ? 'w' : '-';
	perm_str[6] = (st_mode_perm & S_IXGRP) ? 'x' : '-';
	perm_str[7] = (st_mode_perm & S_IROTH) ? 'r' : '-';
	perm_str[8] = (st_mode_perm & S_IWOTH) ? 'w' : '-';
	perm_str[9] = (st_mode_perm & S_IXOTH) ? 'x' : '-';
	return (perm_str);
}
