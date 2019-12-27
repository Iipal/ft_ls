/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_files_as_dir.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:44:51 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/28 01:31:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	parse_args_files_as_dir(struct s_arg *args, int32_t n)
{
	struct s_dir	*d;
	struct stat		st;

	LS_ASSERT(d = ft_memalloc(sizeof(*d)));
	LS_ASSERT(d->objs = ft_memalloc(sizeof(*(d->objs)) * n));
	d->n_objs = -1;
	d->is_file = true;
	while (n > ++d->n_objs)
	{
		init_stat_no_err(args[d->n_objs].path, &st);
		if (!(init_dir_obj(&d->objs[d->n_objs], &st, args[d->n_objs].path)))
		{
			free_dir(&d);
			return ;
		}
	}
	ft_strcpy(g_src_path, ".");
	SET_BIT(g_flags, BIT_NO_TOTAL);
	output(d);
	UNSET_BIT(g_flags, BIT_NO_TOTAL);
	free_dir(&d);
}
