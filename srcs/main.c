/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 16:01:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	g_flags = 0;
char	*g_src_path = NULL;

int32_t	g_main_ret = EXIT_SUCCESS;

static int32_t	g_valid_args_counter = 0;

static t_list	*s_pre_parse_errno_args(int32_t ac, char **av)
{
	t_list		*out;
	struct stat	tmp;
	int32_t		i;

	i = -1;
	out = NULL;
	while (ac > ++i)
		if (init_lstat_check(av[i], &tmp))
		{
			if (!out)
				out = ft_lstnew(av[i], sizeof(char) * ft_strlen(av[i]));
			else
				ft_lstadd(&out, ft_lstnew(av[i],
									sizeof(char) * ft_strlen(av[i])));
			++g_valid_args_counter;
		}
		else
			g_main_ret = EXIT_FAILURE;
	return (out);
}

static void		s_del_list(void *data, size_t size)
{
	(void)size;
	free(data);
}

static int		s_parse_args(int ac, char **av)
{
	t_list	*args;
	t_list	*save;
	int32_t	i;

	i = -1;
	qsort(av, ac, sizeof(char*), sort_ascii_tab_cmp);
	if (!(args = s_pre_parse_errno_args(ac, av)))
		return (g_main_ret = EXIT_FAILURE);
	save = args;
	while (args && g_valid_args_counter > ++i)
	{
		FREE(g_src_path, free);
		g_src_path = ft_strndup((const char*)args->data, args->data_size);
		if (1 < ac)
			ft_printf("%s:\n", g_src_path);
		if (!parse_dir(g_src_path))
			continue ;
		if (g_valid_args_counter != i + 1)
			ft_putchar('\n');
		args = args->next;
	}
	ft_lstdel(&save, s_del_list);
	return (EXIT_SUCCESS);
}

int				main(int argc, char *argv[])
{
	--argc;
	++argv;
	g_src_path = ft_strdup(".");
	if (!argc)
		g_main_ret = !parse_dir(g_src_path);
	else
	{
		while (argc && '-' == **argv && *(*argv + 1))
		{
			NO_R(parse_flags(*argv), EXIT_FAILURE);
			++argv;
			--argc;
		}
		if (0 >= isatty(fileno(stdout)))
			SET_BIT(g_flags, BIT_1_ONE);
		if (!argc)
			g_main_ret = !parse_dir(g_src_path);
		else
			s_parse_args(argc, argv);
	}
	FREE(g_src_path, free);
	return (g_main_ret);
}
