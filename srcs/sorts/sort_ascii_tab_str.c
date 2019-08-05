/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_tab_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:34:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/05 16:14:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	**sort_ascii_tab_str(size_t const n, char **tab)
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
