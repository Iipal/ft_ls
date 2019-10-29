/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 23:35:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	g_flags = 0;
char	*g_src_path = NULL;

int32_t	g_main_ret = EXIT_SUCCESS;

static char	**s_pre_parse_errno_args(int32_t const ac, char **av, int32_t *va)
{
	char		**out;
	struct stat	tmp;
	int			i;
	int			j;

	i = -1;
	j = -1;
	*va = 0;
	while (ac > ++i)
		if (init_lstat_check(av[i], &tmp))
			++(*va);
		else
			g_main_ret = EXIT_FAILURE;
	if (!*va)
		return (av);
	MEM(char*, out, *va, E_ALLOC);
	i = -1;
	va = 0;
	while (ac > ++i)
		if (init_lstat_check_no_errno(av[i], &tmp))
			out[++j] = ft_strdup(av[i]);
	return (out);
}

static bool	s_parse_args(int const ac, char **av)
{
	char	**valid_args;
	int32_t	valid_args_len;
	int32_t	i;

	i = -1;
	av = sort_ascii_tab_str(ac, av);
	if (!(valid_args = s_pre_parse_errno_args(ac, av, &valid_args_len)))
		return (g_main_ret = EXIT_FAILURE);
	while (valid_args_len > ++i)
	{
		if (1 < ac)
			ft_printf("%s:\n", valid_args[i]);
		g_src_path = valid_args[i];
		if (!parse_dir(valid_args[i]))
			continue ;
		if (valid_args_len != i + 1)
			ft_putchar('\n');
	}
	return ((bool)free_valid_args(valid_args, valid_args_len));
}

int			main(int argc, char *argv[])
{
	--argc;
	++argv;
	if (!argc)
		g_main_ret = !parse_dir(".");
	else
	{
		while (argc && '-' == **argv)
		{
			NO_R(parse_flags(*argv), EXIT_FAILURE);
			++argv;
			--argc;
		}
		if (!argc)
			g_main_ret = !parse_dir(".");
		else
			s_parse_args(argc, argv);
	}
	return (g_main_ret);
}
