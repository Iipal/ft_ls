/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/03 16:32:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	s_parse_multifile(size_t const ac, char **av, uint8_t const flags)
{
	size_t i;

	i = ~0ULL;
	av = sort_ascii_tab_str(ac, av);
	while (ac > ++i)
	{
		if (0 < i)
			ft_printf("%s:\n", av[i]);
		if (!parse_dir(av[i], flags))
			continue ;
		if (ac != i + 1)
			ft_putchar('\n');
	}
}

int			main(int argc, char *argv[])
{
	static uint8_t	flags;

	--argc;
	++argv;
	if (!argc)
		parse_dir(".", flags);
	else
	{
		if ('-' == **argv)
		{
			NO_F(parse_flags(*argv, &flags));
			++argv;
			--argc;
		}
		if (!argc)
			return (parse_dir(".", flags));
		else
			s_parse_multifile(argc, argv, flags);
	}
}
