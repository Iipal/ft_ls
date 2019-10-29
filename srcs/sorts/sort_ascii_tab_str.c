/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_tab_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:34:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 16:30:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	**sort_ascii_tab_str(int const n, char **tab)
{
	register int32_t	i;
	register int32_t	j;

	i = -1;
	if (!n || 1 == n)
		return (tab);
	while (n > ++i)
	{
		j = i - 1;
		while (n > ++j)
			if (0 < ft_strcmp(tab[i], tab[j]))
				SWAP(tab[i], tab[j]);
	}
	return (tab);
}
