/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:59:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/18 17:19:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static struct dirent	*add_dup_dirent(struct dirent *src)
{
	struct dirent	*out;

	MEM(struct dirent, out, 1, E_ALLOC);
	*out = *src;
	return (out);
}

static CurrDir	*add_init_curr_dir(string path, const Flags *const flags)
{
	DIR 			*tmp_dir;
	struct dirent	*tmp_dirent;
	CurrDir			*out;
	size_t			i;

	i = ~0ULL;
	(void)flags;
	NODO_F(tmp_dir = opendir(path), perror(PERR));
	MEM(CurrDir, out, 1, E_ALLOC);
	while ((tmp_dirent = readdir(tmp_dir)))
		++out->in_dir_dirents;
	closedir(tmp_dir);
	MEM(struct dirent*, out->dirents, out->in_dir_dirents, E_ALLOC);
	tmp_dir = opendir(path);
	while ((tmp_dirent = readdir(tmp_dir)))
		out->dirents[++i] = add_dup_dirent(tmp_dirent);
	closedir(tmp_dir);
	return (out);
}

static bool	add_parse_dir(string path, Environment *const env)
{
	CurrDir *curr_dir;
	size_t	i;

	i = ~0ULL;
	NO_F(curr_dir = add_init_curr_dir(path, &env->flags));
	ls_free_curr_dir(&curr_dir);
	while (curr_dir->in_dir_dirents > ++i)
		printf("[%zu]: %s\n", i + 1, curr_dir->dirents[i]->d_name);
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
		if ('-' == **av && *(*av + 1))
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
