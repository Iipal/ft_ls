/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 08:57:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	add_check_valid_flag(char flag, uint8_t *const mask)
{
	uint32_t	i;
	const char	flags[MAX_FLAGS] = {F_LIST_CH, F_RECURSIVE_CH,
						F_HIDDEN_CH, F_REVERSE_CH, F_TIME_CH};

	i = ~0;
	while (MAX_FLAGS > ++i)
		if (flag == flags[i])
		{
			SET_BIT(*mask, F_N_BIT(i));
			return (true);
		}
	return (false);
}

bool		ls_parse_flags(string flags, uint8_t *const fmask)
{
	while (*(++flags))
		if (!add_check_valid_flag(*flags, fmask))
		{
			E_ILLEGAL(*flags);
			return (false);
		}
	return (true);
}
