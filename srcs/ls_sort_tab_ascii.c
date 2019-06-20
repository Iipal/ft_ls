/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_tab_ascii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:34:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/20 09:20:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	add_find_max_string_len(const size_t n, const strtab tab)
{
	size_t	i;
	size_t	out_max;

	i = ~0ULL;
	if (!n)
		return (0);
	out_max = ft_strlen(*tab);
	while (n > ++i)
		if (out_max < ft_strlen(tab[i]))
			out_max = ft_strlen(tab[i]);
	return (out_max);
}

strtab			ls_sort_tab_ascii(size_t n, strtab tab)
{
	const size_t	max_string_len = add_find_max_string_len(n, tab) + 1;
	strtab			out;
	char			temp[1024];
	size_t			i;
	size_t			j;

	if (!n)
		return (NULL);
	i = ~0ULL;
	MEM(string, out, n, E_ALLOC);
	while (n > ++i)
	{
		j = i;
		MEM(char, out[i], max_string_len, E_ALLOC);
		out[i] = ft_strcpy(out[i], tab[i]);
		while (n > j)
		{
			if (0 < ft_strcmp(out[i], tab[j]))
			{
				ft_strcpy((string)temp, out[i]);
				ft_strcpy(out[i], tab[j]);
				ft_strcpy(tab[j], (const string)temp);
			}
			++j;
		}
	}
	return (out);
}
