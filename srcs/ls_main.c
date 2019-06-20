/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:59:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/20 13:25:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	add_parse_dir(string path, Environment *const env)
{
	CurrDir *curr_dir;
	size_t	i;

	i = ~0ULL;
	NO_F(curr_dir = ls_init_curr_dir(path, &env->flags));
	if (env->flags.f_t_time_sort)
		ls_sort_stats_time(curr_dir->in_dir_objs, curr_dir->objs,
			env->flags.f_r_reverse_sort);
	else
		ls_sort_dirents_ascii(curr_dir->in_dir_objs, curr_dir->objs,
			env->flags.f_r_reverse_sort);
	while (curr_dir->in_dir_objs > ++i)
	{
		ft_putstr(curr_dir->objs[i].dirent->d_name);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	ls_free_curr_dir(&curr_dir);
	return (true);
}

bool		ls(size_t ac, strtab av)
{
	Environment	*env;
	size_t		i;

	MEM(Environment, env, 1, E_ALLOC);
	if (!ac)
	{
		NODO_F(add_parse_dir(".", env), ls_free(&env));
	}
	else
	{
		if ('-' == **av && *(*av + 1))
		{
			NODO_F(ls_parse_flags(*av, env), ls_free(&env));
			--ac;
			++av;
		}
		env->ac = ac;
		if (!ac)
		{
			NODO_F(add_parse_dir(".", env), ls_free(&env));
		}
		else if (1 == ac)
		{
			NODO_F(add_parse_dir(*av, env), ls_free(&env));
		}
		else
		{
			i = ~0ULL;
			while (ac > ++i)
			{
				env->sorted_av = ls_sort_tab_ascii(ac, av);
				MSG(env->sorted_av[i]);
				MSGN(":");
				NODO_F(add_parse_dir(env->sorted_av[i], env), continue);
				if (ac != i + 1)
					MSGN("\n");
			}
		}
	}
	ls_free(&env);
	return (true);
}
