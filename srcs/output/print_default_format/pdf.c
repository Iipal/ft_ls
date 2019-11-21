/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:41:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline __attribute__((__const__)) struct s_2si
	s_items_output_fmt(const int32_t n_objs)
{
	const float	x = (float)g_win_size.x / (float)((g_max_name_len + 1UL));

	return ((struct s_2si) { x, (float)n_objs / x + 1.0f });
}

void
	pdf(const int32_t n_objs, const struct s_object *restrict objs)
{
	const int32_t	ch_separator = (IS_BIT(g_flags, BIT_1_ONE) ? '\n' : ' ');
	struct s_2si	items_fmt;
	struct s_2si	i;
	int32_t			curr_i;

	i.y = -1;
	items_fmt = s_items_output_fmt(n_objs);
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
