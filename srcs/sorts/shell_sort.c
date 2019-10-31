/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/31 13:15:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <immintrin.h>

void	shell_sort(void *_base, ssize_t const _n_el, size_t const _width,
				int32_t (*_cmp)(void const*, void const*))
{
	__v4di	i;
	void	*_tmp;
	int32_t	cmp;

	if (2 > _n_el)
		return ;
	_tmp = ft_memalloc(_width);
	i[0] = _n_el / 2;
	while (0 < i[0])
	{
		i[1] = i[0];
		while (_n_el > i[1])
		{
			ft_memcpy(_tmp, _base + (i[1] * _width), _width);
			i[2] = i[1];
			while (i[0] <= i[2])
			{
				cmp = _cmp(_tmp, _base + ((i[2] - i[0]) * _width));
				if (0 > cmp)
					ft_memcpy(_base + (i[2] * _width),
						_base + ((i[2] - i[0]) * _width), _width);
				else
					break ;
				i[2] -= i[0];
			}
			ft_memcpy(_base + (i[2] * _width), _tmp, _width);
			++i[1];
		}
		i[0] /= 2;
	}
}
