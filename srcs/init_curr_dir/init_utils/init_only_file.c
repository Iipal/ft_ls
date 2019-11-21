/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_only_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:58:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 21:46:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

CurrDir	*init_only_file(const char *restrict path)
{
	CurrDir		*out;
	struct stat	st;

	if (!init_lstat_check(path, &st))
		return (NULL);
	MEM(CurrDir, out, 1UL, E_ALLOC);
	out->n_objs = 1UL;
	out->is_file = true;
	out->objs = init_curr_in_dir_obj(NULL, &st, NULL, path);
	if (!out->objs)
		out = free_curr_dir(&out);
	return (out);
}
