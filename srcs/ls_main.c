/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:59:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/19 13:28:31 by tmaluh           ###   ########.fr       */
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
	while (curr_dir->in_dir_dirents > ++i)
		printf("[%zu]: %s\n", i + 1, curr_dir->dirents[i]->d_name);
	ls_free_curr_dir(&curr_dir);
	return (true);
}

bool		ls(size_t ac, strtab av)
{
	Environment	*env;
	strtab		sorted_av;
	size_t		i;

	sorted_av = NULL;
	MEM(Environment, env, 1, E_ALLOC);
	if (!ac)
	{
		NODO_F(add_parse_dir(".", env), ls_free(&env));
	}
	else
	{
		sorted_av = ls_sort_ascii(ac, av);
		if ('-' == **av && *(*av + 1))
		{
			NODO_F(ls_parse_flags(*av, env), ls_free(&env));
			--ac;
			++av;
		}
		i = ~0ULL;
		while (ac > ++i)
			NODO_F(add_parse_dir(sorted_av[i], env), ls_free(&env));
	}
	ls_free(&env);
	return (true);
}
