/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:29 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/03 20:32:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline int32_t
	s_flags_dependecy(const int32_t flag)
{
	if (IS_BIT(flag, BIT_G_NO_OWNER))
		SET_BIT(g_flags, BIT_L_LIST);
	else if (IS_BIT(flag, BIT_L_LIST))
		UNSET_BIT(g_flags, BIT_1_ONE);
	else if (IS_BIT(flag, BIT_1_ONE))
		UNSET_BIT(g_flags, BIT_L_LIST);
	else if (IS_BIT(flag, BIT_F_NO_SORT))
		SET_BIT(g_flags, BIT_A_HIDDEN);
	return (flag);
}

static bool
	s_check_valid_flag(const char curr_flag)
{
	static const char	valid_flags[16] = { F_ONE, F_HIDDEN, F_NO_SORTED,
		F_COLOR, F_NO_OWNER, F_LIST, F_RECURSIVE, F_REVERSE, F_SIZE,
		F_FULL_TIME, F_TIME, F_ACCESS };
	ptrdiff_t			i;

	i = 0L;
	while (valid_flags[i] && valid_flags[i] != curr_flag)
		++i;
	if (curr_flag == valid_flags[i])
		return (s_flags_dependecy(SET_BIT(g_flags, TO_N_BIT(i))));
	return (false);
}

int
	s_parse_av_str(const char *flags_str)
{
	while (*(++flags_str))
		if (*flags_str == '-')
			return (0);
		else if (!s_check_valid_flag(*flags_str))
		{
			ft_fprintf(stderr, "ft_ls: illegal option -- %c\n%s\n",
				*flags_str, FLAGS_USAGE);
			return (-1);
		}
	return (1);
}

int
	parse_flags(struct s_arg_av *restrict const a)
{
	int	parse_status;

	while (a->ac && '-' == **(a->av))
	{
		parse_status = s_parse_av_str(*(a->av));
		++a->av;
		--a->ac;
		if (0 > parse_status)
			return (EXIT_FAILURE);
		else if (!parse_status)
			break ;
	}
	return (EXIT_SUCCESS);
}
