/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/12 01:04:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	pdf_objs(const uint32_t n_objs,
			const InDirObject *restrict objs)
{
	uint32_t	i;
	const char	files_separator_ch = (IS_BIT(g_flags, BIT_1_ONE) ? '\n' : ' ');

	i = ~0U;
	while (n_objs > ++i)
	{
		ft_printf("%s", objs[i].dirent->d_name);
		if (n_objs - 1 != i)
			ft_putchar(files_separator_ch);
	}
	ft_putchar('\n');
}
