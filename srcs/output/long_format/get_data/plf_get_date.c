/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:17:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/26 17:02:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline char
	*plf_get_date(char *restrict dst, const struct stat *restrict st)
{
	const int	mon_diff = time(NULL) - st->st_mtime;
	char		*date_str;

	date_str = ctime(IS_BIT(g_flags, BIT_U_ACCESS)
			? &st->st_atime : &st->st_mtime);
	dst = ft_strncpy(dst, date_str + 4UL, 12UL);
	if (TIME_HALF_YEAR <= mon_diff || 0 > mon_diff)
	{
		dst[7] = ' ';
		ft_strncpy(dst + 8UL, date_str + 20UL, 4UL);
	}
	return (dst);
}
