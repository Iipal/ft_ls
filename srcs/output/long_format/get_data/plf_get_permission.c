/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_permission.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:23:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/26 03:39:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*plf_get_permission(char *restrict perm_str, const mode_t st_mode_perm)
{
	const static char	obj_chars[8] = "dcblps-";
	static bool			*obj_types_table;
	bool				*obj_type_ptr_selector;

	obj_types_table = (bool[8]){ S_ISDIR(st_mode_perm), S_ISCHR(st_mode_perm),
		S_ISBLK(st_mode_perm), S_ISLNK(st_mode_perm), S_ISFIFO(st_mode_perm),
		S_ISSOCK(st_mode_perm), 1L, 0L
	};
	obj_type_ptr_selector = obj_types_table;
	while (!*obj_type_ptr_selector)
		++obj_type_ptr_selector;
	perm_str[0] = obj_chars[obj_type_ptr_selector - obj_types_table];
	perm_str[1] = (st_mode_perm & S_IRUSR) ? 'r' : '-';
	perm_str[2] = (st_mode_perm & S_IWUSR) ? 'w' : '-';
	perm_str[3] = (st_mode_perm & S_IXUSR) ? 'x' : '-';
	perm_str[4] = (st_mode_perm & S_IRGRP) ? 'r' : '-';
	perm_str[5] = (st_mode_perm & S_IWGRP) ? 'w' : '-';
	perm_str[6] = (st_mode_perm & S_IXGRP) ? 'x' : '-';
	perm_str[7] = (st_mode_perm & S_IROTH) ? 'r' : '-';
	perm_str[8] = (st_mode_perm & S_IWOTH) ? 'w' : '-';
	perm_str[9] = (st_mode_perm & S_IXOTH) ? 'x' : '-';
	if (st_mode_perm & S_ISVTX)
		perm_str[9] = 'T';
	return (perm_str);
}
