/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/25 19:20:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	main(int ac, char *av[])
{
	struct s_arg_av	a;

	a = (struct s_arg_av) { av + 1, ac - 1 };
	gdi_flags_parser(&a);
	gdi_isatty_value_init();
	if (!a.ac)
		return (!parse_dir("."));
	return (parse_args(&a));
}
