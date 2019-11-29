/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:17:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:56:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline char
	*plf_get_date(char *restrict dst, const struct s_stat *restrict st)
{
	const int	mon_diff = time(NULL) - st->m_time;
	char		*date_str;

	date_str = ctime(IS_BIT(g_flags, BIT_U_ACCESS) ? &st->a_time : &st->m_time);
	dst = ft_strncpy(dst, date_str + 4UL,
		IS_BIT(g_flags, BIT_T_FULL_TIME) ? (ft_strlen(date_str) - 4UL) : 12UL);
	dst[20UL] = 0;
	if (!IS_BIT(g_flags, BIT_T_FULL_TIME)
	&& (TIME_HALF_YEAR <= mon_diff || 0 > mon_diff))
	{
		dst[7] = ' ';
		ft_strncpy(dst + 8UL, date_str + 20UL, 4UL);
	}
	return (dst);
}
