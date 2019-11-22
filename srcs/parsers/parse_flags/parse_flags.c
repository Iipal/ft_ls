/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 10:49:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool			s_check_valid_flag(const char curr_flag)
{
	static char		valid_flags[] = { F_LIST, F_ONE, F_TIME,
			F_NOT_SORTED, F_REVERSE, F_RECURSIVE, F_HIDDEN };
	const size_t	valid_flags_size = ARR_SIZE(valid_flags);
	size_t			i;

	i = ~0UL;
	while (valid_flags_size > ++i)
		if (curr_flag == valid_flags[i])
			return (SET_BIT(g_flags, TO_N_BIT(i)));
	return (false);
}

static inline void	s_flags_dependecy(void)
{
	if (IS_BIT(g_flags, BIT_1_ONE))
		UNSET_BIT(g_flags, BIT_L_LIST);
	if (IS_BIT(g_flags, BIT_F_NOT_SORTED))
		SET_BIT(g_flags, BIT_A_HIDDEN);
}

bool				parse_flags(const char *flags_str)
{
	while (*(++flags_str))
		if (!s_check_valid_flag(*flags_str))
		{
			ft_printf("illegal option -- %c\n", *flags_str);
			return (false);
		}
	s_flags_dependecy();
	return (true);
}
