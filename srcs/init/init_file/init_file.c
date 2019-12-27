/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:58:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/28 01:31:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct s_dir	*init_file(const char *restrict path)
{
	struct s_dir	*out;
	struct stat		st;

	if (!init_stat(path, &st))
		return (NULL);
	LS_ASSERT(out = ft_memalloc(sizeof(*out)));
	out->n_objs = 1UL;
	out->is_file = true;
	out->objs = init_dir_obj(NULL, &st, path);
	return (out);
}
