/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_fmt_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:52:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/25 21:55:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

struct s_lf_spec_width
	plf_width_spec(const uint32_t n_objs,
		const struct s_object *restrict objs,
		t_blkcnt_t *restrict total)
{
	struct s_lf_spec_width	ws;
	struct s_lf_spec_width	ws_temp;
	uint32_t				i;

	i = ~0U;
	ws = (struct s_lf_spec_width) { 0 };
	while (n_objs > ++i)
	{
		ws_temp.st_nlnk_w = ft_digits(objs[i].stat->st_nlink);
		ws_temp.st_size_w = ft_digits(objs[i].stat->st_size);
		ws_temp.pw_name_w = ft_strlen(getpwuid(objs[i].stat->st_uid)->pw_name);
		ws_temp.gr_name_w = ft_strlen(getgrgid(objs[i].stat->st_gid)->gr_name);
		if (ws_temp.st_nlnk_w > ws.st_nlnk_w)
			ws.st_nlnk_w = ws_temp.st_nlnk_w;
		if (ws_temp.st_size_w > ws.st_size_w)
			ws.st_size_w = ws_temp.st_size_w;
		if (ws_temp.pw_name_w > ws.pw_name_w)
			ws.pw_name_w = ws_temp.pw_name_w;
		if (ws_temp.gr_name_w > ws.gr_name_w)
			ws.gr_name_w = ws_temp.gr_name_w;
		if (!(S_ISDIR(objs[i].stat->st_mode)))
			*total += objs[i].stat->st_blocks;
	}
	return (ws);
}

char
	*plf_fmt_str(const struct s_lf_spec_width ws)
{
	char	*fmt_str;
	size_t	curr_offset;

	fmt_str = ft_strnew(STR_LEN_DEFAULT_FMT
				+ ft_digits(ws.st_nlnk_w)
				+ ft_digits(ws.st_size_w)
				+ ft_digits(ws.pw_name_w)
				+ ft_digits(ws.gr_name_w));
	if (!IS_BIT(g_flags, BIT_G_NOT_OWNER))
		sprintf(fmt_str, "%%s%%c %%%zud %%-%zus  %%-%zus  %%%zud %%s %%s",
			ws.st_nlnk_w, ws.pw_name_w, ws.gr_name_w, ws.st_size_w);
	else
		sprintf(fmt_str, "%%s%%c %%%zud %%s%%-%zus  %%%zud %%s %%s",
			ws.st_nlnk_w, ws.pw_name_w, ws.st_size_w);
	return (fmt_str);
}
