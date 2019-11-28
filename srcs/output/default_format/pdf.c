/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 17:25:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline __attribute__((__const__)) t_s2si
	s_fmt(const int32_t n)
{
	const int	win_x = get_term_win_col();
	const float	x = (float)win_x / (float)g_max_name_len;

	return ((t_s2si) { x, (float)n / x + 1.0f});
}

static void
	s_put_sep(size_t d_name_len, const int32_t n, size_t *offset, t_s2si xy)
{
	size_t	n_spaces;

	n_spaces = 0UL;
	g_data_buf[(*offset)++] = IS_BIT(g_flags, BIT_1_ONE) ? '\n' : ' ';
	if (!IS_BIT(g_flags, BIT_1_ONE) && xy.x + 1 < n / (float)xy.y)
	{
		n_spaces = g_max_name_len - d_name_len;
		while (n_spaces--)
			g_data_buf[(*offset)++] = ' ';
	}
}

static inline struct s_pdf
	s_select_output_data(const struct s_object *restrict obj)
{
	return ((struct s_pdf) { obj->clr_name ? obj->clr_name : obj->d_name,
						obj->clr_name ? obj->clr_len : obj->d_name_len });
}

void
	pdf(const int32_t n, const struct s_object *restrict objs)
{
	t_s2si			i;
	t_s2si			fmt;
	size_t			offset;
	int32_t			j;
	struct s_pdf	p;

	i.y = -1;
	offset = 0UL;
	fmt = IS_BIT(g_flags, BIT_1_ONE) ? (t_s2si){999, 1} : s_fmt(n);
	while (fmt.y > ++i.y && (i.x = -1))
	{
		while (fmt.x > ++i.x)
		{
			if (n <= (j = i.x * fmt.y + i.y))
				break ;
			p = s_select_output_data(&objs[j]);
			ft_strncpy(g_data_buf + offset, p.name, p.name_len);
			offset += p.name_len;
			if (n - 1 > j)
				s_put_sep(objs[j].d_name_len, n, &offset, (t_s2si){i.x, fmt.y});
		}
		!IS_BIT(g_flags, BIT_1_ONE) ? (g_data_buf[offset++] = '\n') : 0;
	}
	IS_BIT(g_flags, BIT_1_ONE) ? (g_data_buf[offset++] = '\n') : 0;
	write(STDOUT_FILENO, g_data_buf, offset);
}
