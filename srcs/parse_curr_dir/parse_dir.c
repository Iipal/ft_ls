/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:27:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 19:29:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

bool	parse_dir(char *path)
{
	CurrDir	*cd;

	NO_F(cd = init_curr_dir(path, false));
	if (cd->is_file)
		parse_file(path, cd->objs);
	else
		parse_flags_output(path, cd);
	free_curr_dir(&cd);
	return (true);
}
