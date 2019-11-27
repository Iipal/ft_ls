/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/27 18:04:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline __attribute__((__const__)) t_s2si
	s_fmt(const int32_t n_objs)
{
	const float	x = (float)g_win_size.x / (float)g_max_name_len;

	return ((t_s2si) { x, (float)n_objs / x + 1.11f });
}

static void
	s_put_file_separators(size_t d_name_len,
		const int32_t n_objs,
		size_t *offset,
		t_s2si xy)
{
	size_t	n_spaces;

	n_spaces = 0UL;
	g_data_buf[(*offset)++] = IS_BIT(g_flags, BIT_1_ONE) ? '\n' : ' ';
	if (!IS_BIT(g_flags, BIT_1_ONE) && xy.x + 1 < n_objs / (float)xy.y)
	{
		n_spaces = g_max_name_len - d_name_len;
		while (n_spaces--)
			g_data_buf[(*offset)++] = ' ';
	}
}

void
	pdf(const int32_t n_objs, const struct s_object *restrict objs)
{
	t_s2si	i;
	t_s2si	items_fmt;
	size_t	offset;
	int32_t	curr_i;

	i.y = -1;
	offset = 0UL;
	items_fmt = IS_BIT(g_flags, BIT_1_ONE) ? (t_s2si){999, 1} : s_fmt(n_objs);
	while (items_fmt.y > ++i.y && (i.x = -1))
	{
		while (items_fmt.x > ++i.x)
		{
			if (n_objs <= (curr_i = i.x * items_fmt.y + i.y))
				break ;
			ft_strncpy(g_data_buf + offset,
				objs[curr_i].d_name, objs[curr_i].d_name_len);
			offset += objs[curr_i].d_name_len;
			if (n_objs - 1 > curr_i)
				s_put_file_separators(objs[curr_i].d_name_len, n_objs,
					&offset, (t_s2si){ i.x, items_fmt.y });
		}
		!IS_BIT(g_flags, BIT_1_ONE) ? (g_data_buf[offset++] = '\n') : 0;
	}
	IS_BIT(g_flags, BIT_1_ONE) ? (g_data_buf[offset++] = '\n') : 0;
	write(STDOUT_FILENO, g_data_buf, offset);
}
