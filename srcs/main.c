/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 18:47:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

uint8_t	g_flags = 0;

static void	s_parse_multifile(size_t const ac, char **av)
{
	size_t i;

	i = ~0ULL;
	av = sort_ascii_tab_str(ac, av);
	while (ac > ++i)
	{
		if (0 < i)
			ft_printf("%s:\n", av[i]);
		if (!parse_dir(av[i]))
			continue ;
		if (ac != i + 1)
			ft_putchar('\n');
	}
}

int			main(int argc, char *argv[])
{
	--argc;
	++argv;
	if (!argc)
		parse_dir(".");
	else
	{
		if ('-' == **argv)
		{
			NO_F(parse_flags(*argv));
			++argv;
			--argc;
		}
		if (!argc)
			return (parse_dir("."));
		else
			s_parse_multifile(argc, argv);
	}
}
