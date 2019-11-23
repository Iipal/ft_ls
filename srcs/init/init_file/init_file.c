/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:58:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 10:40:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct s_dir	*init_file(const char *restrict path)
{
	struct s_dir	*out;
	struct stat			st;

	if (!init_stat(path, &st))
		return (NULL);
	if (!(out = ft_memalloc(sizeof(struct s_dir))))
		return (ls_errno_msg(__FILE__, __pfunc__, __LINE__, ""));
	out->n_objs = 1UL;
	out->is_file = true;
	if (!(out->objs = init_dir_obj(NULL, &st, NULL, path)))
		out = free_dir(&out);
	return (out);
}
