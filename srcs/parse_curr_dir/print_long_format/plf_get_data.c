/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:17:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 09:49:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_long_format_listing.h"

char	*plf_get_permission(char *perm_str, mode_t const st_mode_perm)
{
	perm_str[0] = '-';
	if (S_ISDIR(st_mode_perm))
		perm_str[0] = 'd';
	else if (S_ISLNK(st_mode_perm))
		perm_str[0] = 'l';
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

char	*plf_get_date(char *date_dst, t_time_t const date_time)
{
	char const *const	date = ctime(&date_time);

	IFDOR(!date, DEF_STRERR("ls", "plf_get_date"), NULL);
	date_dst = ft_strncpy(date_dst, date + 4UL, 12UL);
	date_dst[12] = '\0';
	return (date_dst);
}

char	*plf_full_path(char *const dst,
			char *const dir_path,
			char *const file_name,
			size_t const dst_max)
{
	ft_memset(dst, 0, sizeof(char) * dst_max);
	ft_strcpy(dst, dir_path);
	if (dst[ft_strlen(dst) - 1] != '/')
		dst[ft_strlen(dst)] = '/';
	ft_strcpy(dst + ft_strlen(dst), file_name);
	return (dst);
}
