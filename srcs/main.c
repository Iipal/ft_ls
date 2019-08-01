/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/01 07:18:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static bool	s_parse_with_ac(size_t ac, char **av)
{
	static uint8_t	flags_bits_mask;
	size_t			i;

	if ('-' == **av)
	{
		NO_F(parse_flags(*av++, &flags_bits_mask));
		--ac;
	}
	if (!ac)
		return (parse_dir(".", flags_bits_mask));
	else
	{
		i = ~0ULL;
		av = sort_ascii_tab_str(ac, av);
		while (ac > ++i)
		{
			(0 < i) ? ft_printf("%s:\n", av[i]) : 0;
			if (!parse_dir(av[i], flags_bits_mask))
				continue ;
			(ac != i + 1) ? ft_putchar('\n') : 0;
		}
	}
	return (true);
}

int			main(int argc, char *argv[])
{
	--argc;
	++argv;
	if (!argc)
		parse_dir(".", 0);
	else
		s_parse_with_ac(argc, argv);
}
