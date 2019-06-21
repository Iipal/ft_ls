/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:59:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/21 08:49:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	add_parse_dir(string path, const Flags *const flags);

static bool	add_check_dirs(CurrDir *curr_dir,
				const Flags *const flags,
				string previous_path)
{
	DIR		*tmp_dir;
	string	full_path;
	size_t	i;

	i = ~0ULL;
	full_path = NULL;
	while (curr_dir->in_dir_objs > ++i)
	{
		if ('/' != previous_path[ft_strlen(previous_path) - 1])
		{
			full_path = ft_strnew(sizeof(char)
				* (ft_strlen(curr_dir->objs[i].dirent->d_name)
				+ ft_strlen(previous_path) + 1));
			full_path = ft_strncpy(full_path, previous_path,
									ft_strlen(previous_path));
			full_path[ft_strlen(previous_path)] = '/';
			full_path = ft_strncat(full_path, curr_dir->objs[i].dirent->d_name,
								ft_strlen(curr_dir->objs[i].dirent->d_name));
		}
		else
			full_path =
				ft_strjoin(previous_path, curr_dir->objs[i].dirent->d_name);
		if (!ft_strcmp(full_path + (ft_strlen(full_path) - 2), "..")
		|| !ft_strcmp(full_path + (ft_strlen(full_path) - 1), "."))
		{
			ft_strdel(&full_path);
			continue ;
		}
		if ((tmp_dir = opendir(full_path)))
		{
			ft_printf("\n%s:\n", full_path);
			add_parse_dir(full_path, flags);
		}
		ft_strdel(&full_path);
	}
	return (true);
}


static bool	add_parse_dir(string path, const Flags *const flags)
{
	CurrDir *curr_dir;
	size_t	i;

	i = ~0ULL;
	NO_F(curr_dir = ls_init_curr_dir(path, flags));
	if (flags->f_t_time_sort)
		ls_sort_stats_time(curr_dir->in_dir_objs, curr_dir->objs,
			flags->f_r_reverse_sort);
	else
		ls_sort_dirents_ascii(curr_dir->in_dir_objs, curr_dir->objs,
			flags->f_r_reverse_sort);
	while (curr_dir->in_dir_objs > ++i)
	{
		ft_printf("%s ", curr_dir->objs[i].dirent->d_name);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	if (flags->f_r_recursive_output)
		add_check_dirs(curr_dir, flags, path);
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
		NODO_F(add_parse_dir(".", &env->flags), ls_free(&env));
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
			NODO_F(add_parse_dir(".", &env->flags), ls_free(&env));
		}
		else if (1 == ac)
		{
			NODO_F(add_parse_dir(*av, &env->flags), ls_free(&env));
		}
		else
		{
			i = ~0ULL;
			while (ac > ++i)
			{
				env->sorted_av = ls_sort_tab_ascii(ac, av);
				MSG(env->sorted_av[i]);
				MSGN(":");
				NODO_F(add_parse_dir(env->sorted_av[i], &env->flags), continue);
				if (ac != i + 1)
					MSGN("\n");
			}
		}
	}
	ls_free(&env);
	return (true);
}
