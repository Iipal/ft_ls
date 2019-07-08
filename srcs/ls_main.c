/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:59:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/08 11:31:29 by tmaluh           ###   ########.fr       */
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

static void	add_print_long_format(InDirObject *restrict const obj)
{
	if (S_ISREG(obj->stat->st_mode))
		ft_putchar('-');
	else if (S_ISDIR(obj->stat->st_mode))
		ft_putchar('d');
	ft_putchar('\n');
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
		if (flags->f_l_list_output)
			add_print_long_format(&curr_dir->objs[i]);
		else
		{
			ft_printf("%s", curr_dir->objs[i].dirent->d_name);
			if (curr_dir->in_dir_objs - 1 != i
			&& ft_strlen(curr_dir->objs[i].dirent->d_name)
				< curr_dir->max_obj_len)
					ft_putnchar(' ', curr_dir->max_obj_len
							- ft_strlen(curr_dir->objs[i].dirent->d_name));
			if (curr_dir->in_dir_objs - 1 != i)
				ft_putchar(' ');
		}
	}
	ft_putchar('\n');
	if (flags->f_r_recursive_output)
		add_check_dirs(curr_dir, flags, path);
	ls_free_curr_dir(&curr_dir);
	return (true);
}

static bool	add_parse_with_ac(size_t ac, strtab av, Environment *env)
{
	size_t	i;

	if ('-' == **av && *(*av + 1))
	{
		NO_F(ls_parse_flags(*av, env));
		--ac;
		++av;
	}
	env->ac = ac;
	if (!env->ac)
		return (add_parse_dir(".", &env->flags));
	else
	{
		i = ~0ULL;
		while (env->ac > ++i)
		{
			env->sorted_av = ls_sort_tab_ascii(env->ac, av);
			if (i)
				ft_printf("%s:\n", env->sorted_av[i]);
			if (!add_parse_dir(env->sorted_av[i], &env->flags))
				continue ;
			if (env->ac != i + 1)
				ft_putchar('\n');
		}
	}
	return (true);
}

bool		ls(size_t ac, strtab av)
{
	Environment	*env;

	MEM(Environment, env, 1, E_ALLOC);
	if (!ac)
	{
		NODO_F(add_parse_dir(".", &env->flags), ls_free(&env));
	}
	else
		NODO_F(add_parse_with_ac(ac, av, env), ls_free(&env));
	ls_free(&env);
	return (true);
}
