/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 15:30:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline int32_t
	s_flags_dependecy(const int32_t flag)
{
	if (IS_BIT(flag, BIT_G_NOT_OWNER))
		SET_BIT(g_flags, BIT_L_LIST);
	else if (IS_BIT(flag, BIT_L_LIST))
		UNSET_BIT(g_flags, BIT_1_ONE);
	else if (IS_BIT(flag, BIT_1_ONE))
		UNSET_BIT(g_flags, BIT_L_LIST);
	else if (IS_BIT(flag, BIT_F_NOT_SORTED))
		SET_BIT(g_flags, BIT_A_HIDDEN);
	return (flag);
}

static bool
	s_check_valid_flag(const char curr_flag)
{
	static char		valid_flags[] = { F_ONE, F_HIDDEN, F_NOT_SORTED,
		F_NOT_OWNER, F_LIST, F_RECURSIVE, F_REVERSE, F_TIME, F_ACCESS };
	const size_t	valid_flags_size = ARR_SIZE(valid_flags);
	size_t			i;

	i = ~0UL;
	while (valid_flags_size > ++i)
		if (curr_flag == valid_flags[i])
			return (s_flags_dependecy(SET_BIT(g_flags, TO_N_BIT(i))));
	return (false);
}

bool
	parse_flags(const char *flags_str)
{
	while (*(++flags_str))
		if (!s_check_valid_flag(*flags_str))
		{
			ft_printf("ft_ls: illegal option -- %c\n%s\n",
				*flags_str, FLAGS_USAGE);
			return (false);
		}
	return (true);
}
