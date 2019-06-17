/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:59:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 20:33:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	add_parse_dir(string path, Environment *const env)
{
	DIR *dir = opendir(path);
	dir->__padding
	(void)env;
	return (true);
}

bool		ls(size_t ac, strtab av)
{
	Environment	*env;

	if (!ac)
		return (true);
	MEM(Environment, env, 1, E_ALLOC);
	if ('-' == **av)
	{
		NODO_F(ls_parse_flags(*av, env), ls_free(&env));
		--ac;
		++av;
	}
	if (!ac)
		NODO_F(add_parse_dir(".", env), ls_free(&env));
	ls_free(&env);
	return (true);
}
