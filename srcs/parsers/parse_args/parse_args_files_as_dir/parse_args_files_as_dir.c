/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_files_as_dir.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:44:51 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/26 02:06:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	parse_args_files_as_dir(struct s_arg *args, int32_t n)
{
	struct s_dir	*d;
	struct stat		st;

	if (!(d = ft_memalloc(sizeof(*d))))
	{
		ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc");
		return ;
	}
	if (!(d->objs = ft_memalloc(sizeof(struct s_object) * n)))
	{
		ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc");
		return ;
	}
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
