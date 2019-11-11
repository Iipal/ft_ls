/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort_ascii_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:27:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/11 18:25:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <immintrin.h>

void	sort_ascii_tab(const size_t n, char **tab)
{
	__v2du	i;

	i[0] = ~0UL;
	while (n > ++i[0])
	{
		i[1] = i[0];
		while (n > ++i[1])
			if (ft_strcmp(tab[i[0]], tab[i[1]]))
				SWAP(tab[i[0]], tab[i[1]]);
	}
}
