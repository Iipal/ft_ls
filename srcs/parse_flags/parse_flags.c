/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 21:49:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static char const	g_valid_print_format[] = { F_LIST_CH, F_ONE };
static char const	g_valid_sorts[] = { F_TIME_CH, F_NOT_SORTED_CH };

static char const	g_valid_specific[] = { F_REVERSE_CH, F_HIDDEN_CH,
						F_RECURSIVE_CH };

static bool	s_check_bits_flags(char const curr_flag)
{
	size_t	i;

	i = ~0UL;
	while (ARR_SIZE(g_valid_specific) > ++i)
		if (g_valid_specific[i] == curr_flag)
		{
			SET_BIT(g_flags, TO_N_BIT(i));
			return (true);
		}
	return (false);
}

static bool	s_check_valid_flag(char const curr_flag)
{
	bool	is_match;
	size_t	i;

	i = ~0UL;
	is_match = false;
	while (ARR_SIZE(g_valid_print_format) > ++i)
		if (g_valid_print_format[i] == curr_flag)
		{
			g_print_format = (enum e_print_format)(i + 1);
			is_match = true;
			break ;
		}
	i = ~0UL;
	while (!is_match && ARR_SIZE(g_valid_sorts) > ++i)
		if (g_valid_sorts[i] == curr_flag)
		{
			g_sort_type = (enum e_sort_type)(i + 1);
			is_match = true;
			break ;
		}
	return (is_match ? is_match : s_check_bits_flags(curr_flag));
}

bool		parse_flags(char const *flags_str)
{
	while (*(++flags_str))
		if (!s_check_valid_flag(*flags_str))
		{
			E_ILLEGAL(*flags_str);
			return (false);
		}
	if (g_sort_type == e_sort_none)
		SET_BIT(g_flags, BIT_A_HIDDEN);
	return (true);
}
