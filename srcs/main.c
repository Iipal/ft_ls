/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 16:19:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
** ls.h:
*/
int32_t	g_main_ret = EXIT_SUCCESS;

int32_t	g_isatty_ret = 0;

char	g_data_buf[1024] = { 0 };
char	g_src_path[1024] = { 0 };

size_t	g_max_name_len = 0UL;

int32_t	g_flags = 0;

int	main(int ac, char *av[])
{
	int	parse_flags_ret;

	--ac;
	++av;
	g_isatty_ret = isatty(STDOUT_FILENO);
	(!g_isatty_ret) ? SET_BIT(g_flags, BIT_1_ONE) : 0;
	if (!ac)
		return (!parse_dir("."));
	while (ac && '-' == **av)
	{
		parse_flags_ret = parse_flags(*av);
		++av;
		--ac;
		if (0 > parse_flags_ret)
			return (EXIT_FAILURE);
		else if (!parse_flags_ret)
			break ;
	}
	if (!ac)
		return (!parse_dir("."));
	parse_args(ac, av);
	return (g_main_ret);
}
