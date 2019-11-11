/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:27:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/11 21:10:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <immintrin.h>

void	sort_ascii_tab(const size_t n, char **tab)
{
	volatile __v2du	i;
	char			*key;

	i[0] = -1L;
	while (n > ++i[0])
	{
		key = tab[i[0]];
		i[1] = i[0] - 1L;
		while (0 <= i[1])
		{
			if (0 >= ft_strcmp(tab[i[1]], key))
				break ;
			tab[i[1] + 1L] = tab[i[1]];
			i[1] -= 1L;
		}
		tab[i[1] + 1L] = key;
	}
}
