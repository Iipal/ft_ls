/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 16:55:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	s_check_valid_flag(char const curr_flag, uint8_t *const flags)
{
	uint32_t	i;
	const char	valid_flags[MAX_FLAGS] = {F_LIST_CH, F_RECURSIVE_CH,
							F_HIDDEN_CH, F_REVERSE_CH, F_TIME_CH};

	i = ~0;
	while (MAX_FLAGS > ++i)
		if (curr_flag == valid_flags[i])
		{
			SET_BIT(*flags, F_N_BIT(i));
			return (true);
		}
	return (false);
}

bool		parse_flags(char const *flags_str, uint8_t *const flags)
{
	while (*(++flags_str))
		if (!s_check_valid_flag(*flags_str, flags))
		{
			E_ILLEGAL(*flags_str);
			return (false);
		}
	return (true);
}
