/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:17:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 22:44:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_long_format_listing.h"

char	*plf_get_permission(char *restrict perm_str, const mode_t st_mode_perm)
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

char	*plf_get_date(char *restrict date_dst,
			const t_time_t date_time)
{
	const char	*date = ctime(&date_time);

	IFDOR(!date, DEF_STRERR(ERR, "plf_get_date"), NULL);
	date_dst = ft_strncpy(date_dst, date + 4UL, 12UL);
	date_dst[12] = '\0';
	return (date_dst);
}
