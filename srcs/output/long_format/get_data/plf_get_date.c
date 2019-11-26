/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:17:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/26 13:36:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline time_t __attribute__((__const__))
	s_get_mon(const time_t file_time)
{
	return (localtime(&file_time)->tm_mon);
}

/*
** date == "Sat Nov 23 12:54:51 2019\n".
** When calling ft_strncpy:
** date + 4 == "Nov 23 12:54:51 2019\n".
** setting third param to 12 for copy only "Nov 23 12:54".
**
** If file_time is older on 6 months or more from now
**  - replacing time in string by year from the end of full-date-string.
*/

inline char
	*plf_get_date(char *restrict date_dst, const t_time_t file_time)
{
	const char		*date = ctime(&file_time);
	const t_time_t	mon_diff = s_get_mon(time(NULL)) - s_get_mon(file_time);

	if (!date)
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "ctime"));
	date_dst = ft_strncpy(date_dst, date + 4UL, 12UL);
	if (6L <= mon_diff)
	{
		date_dst[7] = ' ';
		ft_strncpy(date_dst + 8UL, date + 20UL, 4UL);
	}
	return (date_dst);
}
