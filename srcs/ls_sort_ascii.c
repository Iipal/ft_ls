/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:34:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/19 13:26:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	add_find_max_string_len(const size_t max,
					const strtab strings)
{
	size_t	i;
	size_t	out_max;

	i = ~0ULL;
	if (!max)
		return (0);
	out_max = ft_strlen(*strings);
	while (max > ++i)
		if (out_max < ft_strlen(strings[i]))
			out_max = ft_strlen(strings[i]);
	return (out_max);
}

strtab			ls_sort_ascii(size_t max, strtab strings)
{
	const size_t	max_string_len = add_find_max_string_len(max, strings) + 1;
	char			temp[1024];
	strtab			out;
	size_t			i;
	size_t			j;

	if (!max)
		return (NULL);
	i = ~0ULL;
	if ('-' == **strings && *(*strings + 1))
		++i;
	MEM(string, out, max, E_ALLOC);
	while (max > ++i)
	{
		j = i;
		MEM(char, out[i], max_string_len, E_ALLOC);
		out[i] = ft_strcpy(out[i], strings[i]);
		while (max > j)
		{
			if (0 < ft_strcmp(out[i], strings[j]))
			{
				ft_bzero(temp, sizeof(char) * 1024);
				ft_strcpy((string)temp, out[i]);
				ft_strcpy(out[i], strings[j]);
				ft_strcpy(strings[j], (const string)temp);
			}
			++j;
		}
	}
	return (out);
}
