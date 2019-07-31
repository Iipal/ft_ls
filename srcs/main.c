/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 09:24:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	add_parse_with_ac(size_t ac, strtab av, Environment *env)
{
	size_t	i;

	if ('-' == **av && *(*av + 1))
	{
		NO_F(ls_parse_flags(*av++, &env->flags_mask));
		--ac;
	}
	env->ac = ac;
	if (!env->ac)
		return (ls_parse_dir(".", env->flags_mask));
	else
	{
		i = ~0ULL;
		while (env->ac > ++i)
		{
			env->sorted_av = ls_sort_tab_ascii(env->ac, av);
			(0 < i) ? ft_printf("%s:\n", env->sorted_av[i]) : 0;
			if (!ls_parse_dir(env->sorted_av[i], env->flags_mask))
				continue ;
			(env->ac != i + 1) ? ft_putchar('\n') : 0;
		}
	}
	return (true);
}

int			main(int argc, char *argv[])
{
	Environment *env;

	--argc;
	++argv;
	MEM(Environment, env, 1, E_ALLOC);
	if (!argc)
	{
		NODO_F(ls_parse_dir(".", 0), ls_free(&env));
	}
	else
	{
		NODO_F(add_parse_with_ac(argc, argv, env), ls_free(&env));
	}
	ls_free(&env);
}
