/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:30:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 08:22:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	parse_file(char const *const file,
			InDirObject const *const obj)
{
	if (!IS_BIT(g_flags, BIT_L_LIST))
		ft_putendl(file);
	else
		print_obj_long_format(file, obj);
}
