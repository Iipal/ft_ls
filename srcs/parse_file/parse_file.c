/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:30:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 09:12:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_long_format_listing.h"

void		parse_file(char *file, InDirObject const *const obj)
{
	CurrDir		*cd;
	bool		is_link_parse_as_dir;
	t_blkcnt_t	total;

	cd = NULL;
	is_link_parse_as_dir = false;
	if (!IS_BIT(g_flags, BIT_L_LIST))
	{
		if (S_ISLNK(obj->stat->st_mode))
			is_link_parse_as_dir = true;
		else
			ft_putendl(file);
	}
	else
	{
		if (S_ISLNK(obj->stat->st_mode) && ft_strchr(file, '/'))
			is_link_parse_as_dir = true;
		else
			plf_obj(prepare_output_fmtstr(precalc_output(1UL, obj, &total)),
				file, obj, true);
	}
	if (is_link_parse_as_dir)
	{
		cd = init_curr_dir(file, true);
		parse_flags_output(file, cd);
		free_curr_dir(&cd);
	}
}
