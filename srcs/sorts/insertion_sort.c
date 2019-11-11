/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/12 00:17:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <immintrin.h>

void	isort(void *base,
			const size_t n_el,
			const size_t width,
			int32_t (*comparator)(const void*, const void*))
{
	volatile __v2di	i;
	void			*key;

	if (2 > n_el)
		return ;
	i[0] = 0L;
	key = ft_memalloc(width);
	while ((ssize_t)n_el > ++i[0])
	{
		key = ft_memcpy(key, base + (i[0] * width), width);
		i[1] = i[0] - 1L;
		while (0 <= i[1])
		{
			if (0 >= comparator(base + (i[1] * width), key))
				break ;
			ft_memmove(base + ((i[1] + 1L) * width),
				base + (i[1] * width), width);
			i[1] -= 1L;
		}
		ft_memmove(base + ((i[1] + 1L) * width), key, width);
	}
	ft_memdel(&key);
}
