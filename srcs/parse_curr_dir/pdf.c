/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/16 21:01:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	pdf_objs(const uint32_t n_objs, const InDirObject *restrict objs)
{
	const int32_t	ch_separator = (IS_BIT(g_flags, BIT_1_ONE) ? 0xA : 0x20);
	uint32_t		i;

	i = ~0U;
	while (n_objs > ++i)
	{
		ft_printf("%s", objs[i].dirent->d_name);
		if (!IS_BIT(g_flags, BIT_1_ONE))
			ft_putnchar(' ', g_max_name_len - objs[i].d_name_len);
		if (n_objs - 1 != i)
			ft_putchar(ch_separator);
	}
	ft_putchar('\n');
}
