/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 16:18:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	s_find_max_len(const uint32_t n_objs,
					const InDirObject *restrict objs)
{
	s2ul	i;
	size_t	max;

	i = (s2ul) { ~0UL, n_objs };
	max = objs->d_name_len;
	while (n_objs / 2 >= ++i.x && n_objs / 2 <= --i.y)
	{
		if (max < objs[i.x].d_name_len)
			max = objs[i.x].d_name_len;
		if (max < objs[i.y].d_name_len)
			max = objs[i.y].d_name_len;
	}
	return (max);
}

void			pdf_objs(const uint32_t n_objs,
					const InDirObject *restrict objs)
{
	const int32_t	ch_separator = (IS_BIT(g_flags, BIT_1_ONE) ? 0xA : 0x20);
	const size_t	max_len = s_find_max_len(n_objs, objs);
	uint32_t		i;

	i = ~0U;
	while (n_objs > ++i)
	{
		ft_printf("%s", objs[i].dirent->d_name);
		if (!IS_BIT(g_flags, BIT_1_ONE))
			ft_putnchar(' ', max_len - objs[i].d_name_len);
		if (n_objs - 1 != i)
			ft_putchar(ch_separator);
	}
	ft_putchar('\n');
}
