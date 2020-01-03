/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:14 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/03 20:35:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	g_isatty_ret = 0;

int32_t	g_flags = 0;

size_t	g_max_name_len = 0UL;

char	g_data_buf[1024] = { 0 };
char	g_src_path[1024] = { 0 };

int		main(int ac, char *av[])
{
	struct s_arg_av	a;

	a = (struct s_arg_av) { av + 1, ac - 1, { 0 } };
	parse_flags(&a);
	check_isatty();
	if (!a.ac)
		return (!parse_dir("."));
	return (parse_args(&a));
}
