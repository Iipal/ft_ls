/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_fmt_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:52:38 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:56:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

struct s_lf_spec_width
	s_lfsw(const size_t n_objs,
		const struct s_object *restrict objs,
		t_blkcnt_t *restrict total)
{
	struct s_lf_spec_width	ws;
	struct s_lf_spec_width	tmp;
	size_t					i;

	i = ~0UL;
	ws = (struct s_lf_spec_width) { 0 };
	while (n_objs > ++i)
	{
		tmp.st_nlnk_w = ft_digits(objs[i].st->nlink);
		tmp.st_size_w = S_ISCHR(objs[i].st->mode)
						? 8UL : ft_digits(objs[i].st->size);
		tmp.pw_name_w = ft_strlen(getpwuid(objs[i].st->uid)->pw_name);
		tmp.gr_name_w = ft_strlen(getgrgid(objs[i].st->gid)->gr_name);
		ws = (struct s_lf_spec_width) {
			(tmp.st_nlnk_w > ws.st_nlnk_w) ? tmp.st_nlnk_w : ws.st_nlnk_w,
			(tmp.st_size_w > ws.st_size_w) ? tmp.st_size_w : ws.st_size_w,
			(tmp.pw_name_w > ws.pw_name_w) ? tmp.pw_name_w : ws.pw_name_w,
			(tmp.gr_name_w > ws.gr_name_w) ? tmp.gr_name_w : ws.gr_name_w
		};
		*total += objs[i].st->blocks;
	}
	return (ws);
}

inline char
	*plf_get_fmt_str(const size_t n_objs,
		const struct s_object *restrict objs,
		t_blkcnt_t *restrict total)
{
	struct s_lf_spec_width	ws;

	ws = s_lfsw(n_objs, objs, total);
	if (!GDI_FLAGS_IS_BIT(BIT_G_NO_OWNER))
		ft_sprintf(GDI_DBUF_GET_VALUE(),
			"%%s%%c %%%zulu %%-%zus  %%-%zus  %%%zus %%s %%s",
			ws.st_nlnk_w, ws.pw_name_w, ws.gr_name_w, ws.st_size_w);
	else
		ft_sprintf(GDI_DBUF_GET_VALUE(),
			"%%s%%c %%%zuzu %%s%%-%zus  %%%zus %%s %%s",
			ws.st_nlnk_w, ws.gr_name_w, ws.st_size_w);
	return (GDI_DBUF_GET_VALUE());
}
