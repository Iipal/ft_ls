/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_fmt_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:52:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/30 13:06:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_long_format_listing.h"

WidthSpecific		plf_width_spec(uint32_t const n_objs,
						InDirObject const *const objs,
						t_blkcnt_t *const total)
{
	WidthSpecific	ws;
	WidthSpecific	ws_temp;
	uint32_t		i;

	i = ~0U;
	ws.st_nlink_width = 0;
	ws.st_size_width = 0;
	while (n_objs > ++i)
	{
		ws_temp.st_nlink_width = ft_digits(objs[i].stat->st_nlink);
		if (ws_temp.st_nlink_width > ws.st_nlink_width)
			ws.st_nlink_width = ws_temp.st_nlink_width;
		ws_temp.st_size_width = ft_digits(objs[i].stat->st_size);
		if (ws_temp.st_size_width > ws.st_size_width)
			ws.st_size_width = ws_temp.st_size_width;
		if (!(S_ISDIR(objs[i].stat->st_mode)))
			*total += objs[i].stat->st_blocks;
	}
	return (ws);
}

static inline void	s_fmtcat_int(char *dst, int32_t num)
{
	char	*temp;

	temp = ft_itoa(num);
	ft_strcpy(dst, temp);
	free(temp);
}

char				*plf_fmt_str(WidthSpecific const ws)
{
	size_t const	d_nlink_w = ft_digits(ws.st_nlink_width);
	size_t const	d_size_w = ft_digits(ws.st_size_width);
	size_t			curr_offset;
	char			*fmt_str;

	MEM(char, fmt_str, STR_LEN_DEFAULT_FMT + d_nlink_w + d_size_w, E_ALLOC);
	ft_strcpy(fmt_str, "%s  %");
	curr_offset = sizeof("%s  %") - 1UL;
	s_fmtcat_int(fmt_str + curr_offset, ws.st_nlink_width);
	curr_offset += d_nlink_w;
	ft_strcpy(fmt_str + curr_offset, "d %s  %s  %");
	curr_offset += sizeof("d %s  %s  %") - 1UL;
	s_fmtcat_int(fmt_str + curr_offset, ws.st_size_width);
	curr_offset += d_size_w;
	ft_strcpy(fmt_str + curr_offset, "d %s %s");
	return (fmt_str);
}
