/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 23:37:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		g_flags = 0;

static char	**s_pre_parse_errno_args(int const ac, char **av, int *valid_args)
{
	char		**out;
	struct stat	tmp;
	int			i;
	int			j;

	i = -1;
	j = -1;
	*valid_args = 0;
	while (ac > ++i)
		if (init_lstat_check(av[i], &tmp))
			++(*valid_args);
	if (!*valid_args)
		return (av);
	MEM(char*, out, *valid_args, E_ALLOC);
	i = -1;
	valid_args = 0;
	while (ac > ++i)
		if (init_lstat_check_no_errno(av[i], &tmp))
			out[++j] = ft_strdup(av[i]);
	return (out);
}

static bool	s_parse_multifile(int const ac, char **av)
{
	char	**valid_args;
	int		valid_args_len;
	int		i;

	i = -1;
	av = sort_ascii_tab_str(ac, av);
	valid_args = s_pre_parse_errno_args(ac, av, &valid_args_len);
	if (!valid_args)
		return (false);
	while (valid_args_len > ++i)
	{
		if (1 < ac)
			ft_printf("%s:\n", valid_args[i]);
		if (!parse_dir(valid_args[i]))
			continue ;
		if (valid_args_len != i + 1)
			ft_putchar('\n');
	}
	valid_args = free_valid_args(valid_args, valid_args_len);
	return (true);
}

int			main(int argc, char *argv[])
{
	--argc;
	++argv;
	if (!argc)
		return (!parse_dir("."));
	else
	{
		while (argc && '-' == **argv)
		{
			NO_R(parse_flags(*argv), EXIT_FAILURE);
			++argv;
			--argc;
		}
		if (!argc)
			return (!parse_dir("."));
		else
			return (!s_parse_multifile(argc, argv));
	}
}
