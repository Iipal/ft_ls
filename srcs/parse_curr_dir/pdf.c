/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 12:08:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline __attribute__((__const__))
s2si	s_get_current_items_output_format_size(const int32_t n_objs)
{
	const float	x = (float)g_win_size.x / (float)((g_max_name_len + 1UL));

	return ((s2si) { x, (float)n_objs / x + 1.0f });
}

void	pdf_objs(const int32_t n_objs, const InDirObject *restrict objs)
{
	const int32_t	ch_separator = (IS_BIT(g_flags, BIT_1_ONE) ? '\n' : ' ');
	const s2si		items_fmt = s_get_current_items_output_format_size(n_objs);
	int32_t			curr_i;
	s2si			i;

	i.y = -1;
	while (items_fmt.y > ++i.y && (i.x = -1))
	{
		while (items_fmt.x > ++i.x)
		{
			curr_i = i.x * items_fmt.y + i.y;
			if (n_objs <= curr_i)
				break ;
			ft_printf("%s", objs[curr_i].dirent->d_name);
			if (items_fmt.x - 1 != i.x)
			{
				ft_putchar(ch_separator);
				if (!IS_BIT(g_flags, BIT_1_ONE))
					ft_putnchar(' ', g_max_name_len - objs[curr_i].d_name_len);
			}
		}
		if (!IS_BIT(g_flags, BIT_1_ONE))
			ft_putchar('\n');
	}
}
