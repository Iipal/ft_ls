/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:30:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/05 19:12:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	parse_file(char const *const file,
			InDirObject const *const obj)
{
	if (!IS_BIT(g_flags, F_L_LIST))
		ft_putendl(file);
	else
		print_obj_long_format(file, obj);
}
