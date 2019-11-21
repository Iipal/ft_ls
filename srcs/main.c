/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 18:12:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	g_flags = 0;
char	*g_src_path = NULL;
size_t	g_max_name_len = 0UL;
s2si	g_win_size = { 100, 100 };

int32_t	g_main_ret = EXIT_SUCCESS;

int	main(int argc, char *argv[])
{
	--argc;
	++argv;
	NO_R(get_term_win_size(), EXIT_FAILURE);
	g_src_path = ft_strdup(".");
	if (!argc)
		g_main_ret = !parse_dir(g_src_path);
	else
	{
		while (argc && '-' == **argv && *(*argv + 1))
		{
			if (!parse_flags(*argv))
				return (EXIT_FAILURE);
			++argv;
			--argc;
		}
		if (!isatty(fileno(stdout)))
			SET_BIT(g_flags, BIT_1_ONE);
		if (!argc)
			g_main_ret = !parse_dir(g_src_path);
		else
			parse_args(argc, argv);
	}
	ft_strdel(&g_src_path);
	return (g_main_ret);
}
