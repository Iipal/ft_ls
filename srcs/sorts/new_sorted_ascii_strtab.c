/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sorted_ascii_strtab.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:34:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/07/31 17:21:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	**new_sorted_ascii_tab(size_t const n, char **tab)
{
	size_t			i;
	size_t			j;

	i = ~0ULL;
	while (n > ++i)
	{
		j = i - 1ULL;
		while (n > ++j)
			if (0 < ft_strcmp(tab[i], tab[j]))
				SWAP(tab[i], tab[j]);
	}
	return (tab);
}
