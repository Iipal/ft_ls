/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/01 08:05:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_long_format_listing.h"

static void	s_get_permission(char *const perm_str, mode_t const st_mode_perm)
{
	perm_str[0] = (S_ISDIR(st_mode_perm))  ? 'd' : '-';
	perm_str[1] = (st_mode_perm & S_IRUSR) ? 'r' : '-';
	perm_str[2] = (st_mode_perm & S_IWUSR) ? 'w' : '-';
	perm_str[3] = (st_mode_perm & S_IXUSR) ? 'x' : '-';
	perm_str[4] = (st_mode_perm & S_IRGRP) ? 'r' : '-';
	perm_str[5] = (st_mode_perm & S_IWGRP) ? 'w' : '-';
	perm_str[6] = (st_mode_perm & S_IXGRP) ? 'x' : '-';
	perm_str[7] = (st_mode_perm & S_IROTH) ? 'r' : '-';
	perm_str[8] = (st_mode_perm & S_IWOTH) ? 'w' : '-';
	perm_str[9] = (st_mode_perm & S_IXOTH) ? 'x' : '-';
}

void	print_long_format(InDirObject *const curr_obj)
{
	static LongFormatCurrData data;

	data = (LongFormatCurrData) { (char[PERMISSION_STRING_LENGTH]){ 0 },
		getpwuid(curr_obj->stat->st_uid), getgrgid(curr_obj->stat->st_gid)};
	s_get_permission(data.permission, curr_obj->stat->st_mode);
	ft_printf("%s %d %s %s %d %d %s\n", data.permission,
		curr_obj->stat->st_nlink, data.pw->pw_name, data.gp->gr_name,
		curr_obj->stat->st_size, curr_obj->stat->st_ctime,
		curr_obj->dirent->d_name);
}
