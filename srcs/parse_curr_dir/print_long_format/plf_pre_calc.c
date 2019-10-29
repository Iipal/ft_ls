/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_pre_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:52:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 18:49:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_long_format_listing.h"

WidthSpecific	plf_width_spec(uint32_t const n_objs,
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

char			*plf_fmt_str(WidthSpecific const ws)
{
	char	*fmt_str;
	char	*digits_str_tmp;

	MEM(char, fmt_str,
		STR_LEN_DEFAULT_FMT
		+ ft_digits(ws.st_nlink_width)
		+ ft_digits(ws.st_size_width), E_ALLOC);
	ft_strcpy(fmt_str, "%s  %");
	digits_str_tmp = ft_itoa(ws.st_nlink_width);
	ft_strcpy(fmt_str + ft_strlen(fmt_str), digits_str_tmp);
	free(digits_str_tmp);
	ft_strcpy(fmt_str + ft_strlen(fmt_str), "d %s  %s  %");
	digits_str_tmp = ft_itoa(ws.st_size_width);
	ft_strcpy(fmt_str + ft_strlen(fmt_str), digits_str_tmp);
	free(digits_str_tmp);
	ft_strcpy(fmt_str + ft_strlen(fmt_str), "d %s %s");
	return (fmt_str);
}
