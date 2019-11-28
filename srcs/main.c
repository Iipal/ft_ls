/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 17:21:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
** ls.h:
*/
int32_t	g_main_ret = EXIT_SUCCESS;
char	g_data_buf[4096] = { 0 };

int32_t	g_flags = 0;

int32_t	g_isatty_ret = 0;

char	g_src_path[2048] = { 0 };
size_t	g_max_name_len = 0UL;

bool	g_is_print_total = true;

int	main(int ac, char *av[])
{
	--ac;
	++av;
	g_isatty_ret = isatty(STDOUT_FILENO);
	(!g_isatty_ret) ? SET_BIT(g_flags, BIT_1_ONE) : 0;
	if (!ac)
		g_main_ret = !parse_dir(".");
	else
	{
		while (ac && '-' == **av && *(*av + 1))
		{
			if (!parse_flags(*av))
				return (EXIT_FAILURE);
			++av;
			--ac;
		}
		(!ac) ? (g_main_ret = !parse_dir(".")) : parse_args(ac, av);
	}
	return (g_main_ret);
}
