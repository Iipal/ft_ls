/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:05:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/18 15:21:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	add_check_valid_flag(char flag, Environment *const env)
{
	const char	flags[MAX_FLAGS] = {F_LIST_CHAR, F_RECURSIVE_CHAR,
		F_HIDDEN_CHAR, F_REVERSE_CHAR, F_TIME_CHAR};
	bool		**f_bool;
	size_t		i;

	f_bool = (bool*[]){&env->flags.f_l_list_output,
		&env->flags.f_r_recursive_output, &env->flags.f_a_show_hidden,
		&env->flags.f_r_reverse_sort, &env->flags.f_t_time_sort};
	i = ~0ULL;
	while (MAX_FLAGS > ++i)
		if (flag == flags[i])
			return (*f_bool[i] = true);
	return (false);
}

bool		ls_parse_flags(string flags, Environment *const env)
{
	while (*(++flags))
		if (!add_check_valid_flag(*flags, env))
		{
			E_ILLEGAL(*flags);
			return (false);
		}
	return (true);
}
