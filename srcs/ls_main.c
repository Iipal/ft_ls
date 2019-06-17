/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:59:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 22:02:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	add_parse_dir(string path, Environment *const env)
{
	DIR *const	dir = opendir(path);
	struct dirent *dp;

	NODO_F(dir, perror(PERR));
	size_t	i;
	i = ~0ULL;
	while ((dp = readdir(dir)))
		printf("[%zu]: %s\n", ++i + 1, dp->d_name);
	(void)env;
	closedir(dir);
	return (true);
}

bool		ls(size_t ac, strtab av)
{
	Environment	*env;

	MEM(Environment, env, 1, E_ALLOC);
	if (!ac)
	{
		NODO_F(add_parse_dir(".", env), ls_free(&env));
	}
	else
	{
		if ('-' == **av)
		{
			NODO_F(ls_parse_flags(*av, env), ls_free(&env));
			--ac;
			++av;
		}
		if (!ac)
		{
			NODO_F(add_parse_dir(".", env), ls_free(&env));
		}
		else
			NODO_F(add_parse_dir(*av, env), ls_free(&env));
	}
	ls_free(&env);
	return (true);
}
