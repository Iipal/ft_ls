/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:38 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:08:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline struct s_object
	*init_dir_obj(struct s_object *restrict dst,
		const struct stat *restrict st,
		const char *restrict filename)
{
	struct s_object *out;

	out = dst;
	LS_ASSERT(!(!dst && !(out = ft_memalloc(sizeof(*out)))));
	if (st)
		out->st = dup_stat(st);
	out->d_name_len = ft_strlen(filename);
	out->d_name = ft_strndup(filename, out->d_name_len);
	out->acl_ch = init_acl_ea(filename);
	gdi_maxlen_cmp(out->d_name_len);
	if (GDI_ISATTY_GET_VALUE() && GDI_FLAGS_IS_BIT(BIT_G_COLOR))
		out->clr_name = init_file_color(filename, out->d_name_len,
									out->st->mode, &out->clr_len);
	return (out);
}
