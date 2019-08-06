/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 18:48:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	s_check_valid_flag(char const curr_flag)
{
	const char	valid_flags[MAX_LS_FLAGS] = {F_LIST_CH, F_RECURSIVE_CH,
		F_HIDDEN_CH, F_REVERSE_CH, F_TIME_CH, F_NOT_SORTED_CH};
	uint32_t	i;

	i = ~0U;
	while (MAX_LS_FLAGS > ++i)
		if (curr_flag == valid_flags[i])
		{
			SET_BIT(g_flags, TO_N_BIT(i));
			return (true);
		}
	return (false);
}

bool		parse_flags(char const *flags_str)
{
	while (*(++flags_str))
		if (!s_check_valid_flag(*flags_str))
		{
			E_ILLEGAL(*flags_str);
			return (false);
		}
	if (IS_BIT(g_flags, F_F_NOT_SORTED))
		SET_BIT(g_flags, F_A_HIDDEN);
	return (true);
}
