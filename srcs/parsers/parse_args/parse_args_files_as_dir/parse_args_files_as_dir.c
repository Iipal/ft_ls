/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_files_as_dir.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:44:51 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/05 20:37:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	parse_args_files_as_dir(struct s_arg *args, int32_t n)
{
	struct s_dir	*dir;
	struct stat		st;

	if (!(dir = ft_memalloc(sizeof(*dir))))
		return ((void)ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc"));
	if (!(dir->objs = ft_memalloc(sizeof(struct s_object) * n)))
		return ((void)ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc"));
	dir->n_objs = -1;
	dir->is_file = true;
	while (n > ++dir->n_objs)
	{
		init_stat_no_err(args[dir->n_objs].path, &st);
		if (!(init_dir_obj(&dir->objs[dir->n_objs],
							&st, args[dir->n_objs].path)))
			return ((void)free_dir(&dir));
	}
	ft_strcpy(g_src_path, ".");
	SET_BIT(g_flags, BIT_NO_TOTAL);
	output(NULL, dir);
	UNSET_BIT(g_flags, BIT_NO_TOTAL);
	free_dir(&dir);
}
