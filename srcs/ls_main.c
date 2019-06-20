/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:59:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/20 09:54:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	add_parse_dir(string path, Environment *const env)
{
	CurrDir *curr_dir;
	size_t	i;

	i = ~0ULL;
	NODO_F(curr_dir = ls_init_curr_dir(path, &env->flags),
		ls_free_curr_dir(&curr_dir));
	// ls_sort_stats_time(curr_dir->in_dir_objs, curr_dir->objs);
	ls_sort_dirents_ascii(curr_dir->in_dir_objs, curr_dir->objs);
	while (curr_dir->in_dir_objs > ++i)
		printf("%s ", curr_dir->objs[i].dirent->d_name);
	printf("\n");
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
		i = ~0ULL;
		env->ac = ac;
		env->sorted_av = ls_sort_tab_ascii(ac, av);
		if (1 == ac)
		{
			NODO_F(add_parse_dir(*(env->sorted_av), env), ls_free(&env));
		}
		else
		{
			while (ac > ++i)
			{
				MSG(env->sorted_av[i]);
				MSGN(":");
				NODO_F(add_parse_dir(env->sorted_av[i], env), ls_free(&env));
				if (ac != i + 1)
					MSGN("\n");
			}
		}
	}
	ls_free(&env);
	return (true);
}
