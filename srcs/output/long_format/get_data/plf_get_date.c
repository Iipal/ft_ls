/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:17:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/26 16:26:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline int __attribute__((__const__))
	s_get_mon(const time_t file_time)
{
	return (localtime(&file_time)->tm_mon);
}

/*
** date == "Sat Nov 23 12:54:51 2019\n".
** When calling ft_strncpy:
** date + 4 == "Nov 23 12:54:51 2019\n".
** setting third param to 12 to copy only "Nov 23 12:54".
**
** If file_time is older more than 6 months or more from now
**  - replacing time in string with a year from the end of full-date-string.
*/

inline char
	*plf_get_date(char *restrict dst, const struct stat *restrict st)
{
	const int	mon_diff = s_get_mon(time(NULL)) - s_get_mon(st->st_ctime);
	char		*date_str;

	date_str = ctime(IS_BIT(g_flags, BIT_U_ACCESS)
			? &st->st_atime : &st->st_mtime);
	dst = ft_strncpy(dst, date_str + 4UL, 12UL);
	if (6 <= mon_diff || 0 > mon_diff)
	{
		date_str = ctime(&st->st_ctime);
		dst = ft_strncpy(dst, date_str + 4UL, 12UL);
		dst[7] = ' ';
		ft_strncpy(dst + 8UL, date_str + 20UL, 4UL);
	}
	return (dst);
}
