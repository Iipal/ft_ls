/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_fmt_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:52:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 13:41:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

struct s_lf_spec_width
	s_lfsw(const int32_t n_objs,
		const struct s_object *restrict objs,
		t_blkcnt_t *restrict total)
{
	struct s_lf_spec_width	ws;
	struct s_lf_spec_width	tmp;
	int32_t					i;

	i = -1;
	ws = (struct s_lf_spec_width) { 0 };
	while (n_objs > ++i)
	{
		tmp.st_nlnk_w = ft_digits(objs[i].stat->st_nlink);
		tmp.st_size_w = S_ISCHR(objs[i].stat->st_dev)
			? 0UL : ft_digits(objs[i].stat->st_size);
		tmp.pw_name_w = ft_strlen(getpwuid(objs[i].stat->st_uid)->pw_name);
		tmp.gr_name_w = ft_strlen(getgrgid(objs[i].stat->st_gid)->gr_name);
		ws = (struct s_lf_spec_width) {
			(tmp.st_nlnk_w > ws.st_nlnk_w) ? tmp.st_nlnk_w : ws.st_nlnk_w,
			(tmp.st_size_w > ws.st_size_w) ? tmp.st_size_w : ws.st_size_w,
			(tmp.pw_name_w > ws.pw_name_w) ? tmp.pw_name_w : ws.pw_name_w,
			(tmp.gr_name_w > ws.gr_name_w) ? tmp.gr_name_w : ws.gr_name_w
		};
		*total += objs[i].stat->st_blocks;
	}
	return (ws);
}

inline char
	*plf_get_fmt_str(const int32_t n_objs,
		const struct s_object *restrict objs,
		t_blkcnt_t *restrict total)
{
	struct s_lf_spec_width	ws;
	size_t					curr_offset;

	ws = s_lfsw(n_objs, objs, total);
	if (!IS_BIT(g_flags, BIT_G_NOT_OWNER))
		ft_sprintf(g_data_buf, "%%s%%c %%%zud %%-%zus  %%-%zus  %%%zus %%s %%s",
			ws.st_nlnk_w, ws.pw_name_w, ws.gr_name_w, ws.st_size_w);
	else
		ft_sprintf(g_data_buf, "%%s%%c %%%zud %%s%%-%zus  %%%zus %%s %%s",
			ws.st_nlnk_w, ws.gr_name_w, ws.st_size_w);
	return (g_data_buf);
}
