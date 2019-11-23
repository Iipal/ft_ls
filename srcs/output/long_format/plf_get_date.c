/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:17:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 13:01:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline char
	*plf_get_date(char *restrict date_dst, const t_time_t date_time)
{
	const char	*date = ctime(&date_time);

	if (!date)
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, ""));
	date_dst = ft_strncpy(date_dst, date + 4UL, 12UL);
	date_dst[12] = '\0';
	return (date_dst);
}
