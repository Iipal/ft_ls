/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_tab_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:34:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 17:24:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	**sort_ascii_tab_str(size_t const n, char **tab)
{
	size_t			i;
	size_t			j;

	i = ~0ULL;
	if (!n || 1UL == n)
		return (tab);
	while (n > ++i)
	{
		j = i - 1UL;
		while (n > ++j)
			if (0 < ft_strcmp(tab[i], tab[j]))
				SWAP(tab[i], tab[j]);
	}
	return (tab);
}
