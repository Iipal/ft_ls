/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:30:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 17:39:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

bool	parse_file(char const *const file,
			uint8_t const flags,
			struct stat const *const st)
{
	(void)st;
	if (!IS_BIT(flags, F_L_LIST))
		ft_putendl(file);
	return (true);
}
