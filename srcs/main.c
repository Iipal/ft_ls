/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:20:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int ac, char *av[])
{
	struct s_arg_av	a;

	a = (struct s_arg_av) { av + 1, ac - 1, { 0 } };
	if (parse_flags(&a))
		return (EXIT_FAILURE);
	gdi_isatty_value_init();
	if (!a.ac)
		return (!parse_dir("."));
	return (parse_args(&a));
}
