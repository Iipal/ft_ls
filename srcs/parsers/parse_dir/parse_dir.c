/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:27:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/27 22:04:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline bool	parse_dir(const char *restrict path)
{
	struct s_dir	*cd;

	ft_strcpy(g_src_path, path);
	if (!(cd = init_dir(path, false)))
		return (false);
	if (cd->is_file)
		parse_file(path, cd->objs, true);
	else
		output(path, cd);
	free_dir(&cd);
	return (true);
}
