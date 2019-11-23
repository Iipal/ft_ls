/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 13:30:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
** ls_output.h:
*/
char	*g_src_path = NULL;
size_t	g_max_name_len = 0UL;

/*
** ls_system.h:
*/
t_s2si	g_win_size = { 100, 100 };
int32_t	g_isatty_ret = 0;

/*
** ls_falgs.h:
*/
int32_t	g_flags = 0;

/*
** ls.h:
*/
int32_t	g_main_ret = EXIT_SUCCESS;

int	main(int ac, char *av[])
{
	--ac;
	++av;
	if (!get_term_win_size())
		return (EXIT_FAILURE);
	g_isatty_ret = isatty(STDOUT_FILENO);
	g_src_path = ft_strdup(".");
	(!g_isatty_ret) ? SET_BIT(g_flags, BIT_1_ONE) : 0;
	if (!ac)
		g_main_ret = !parse_dir(g_src_path);
	else
	{
		while (ac && '-' == **av && *(*av + 1))
		{
			if (!parse_flags(*av))
				return (EXIT_FAILURE);
			++av;
			--ac;
		}
		(!ac) ? (g_main_ret = !parse_dir(g_src_path)) : parse_args(ac, av);
	}
	ft_strdel(&g_src_path);
	return (g_main_ret);
}
