/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 18:42:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <immintrin.h>

static size_t	g_width = 0UL;
static int		(*g_comparator)(const void*, const void*) = NULL;

static ssize_t	s_partition(void *_base,
					register const ssize_t start,
					register const ssize_t end)
{
	ssize_t	j;
	ssize_t	i;
	void	*pivot;

	j = start - 1L;
	i = start - 1L;
	pivot = ft_memdup(_base + (end * g_width), g_width);
	while (end - 1L >= ++j)
		if (0 >= g_comparator(_base + (j * g_width), pivot))
			ft_memswap(_base + (++i * g_width),
						_base + (j  * g_width), g_width);
	ft_memswap(_base + (++i * g_width), _base + (end * g_width), g_width);
	ft_memdel(&pivot);
	return (i);
}

static void		qsort_recursion(void *_base,
					register const ssize_t start,
					register const ssize_t end)
{
	ssize_t	pivot;

	if (start >= end)
		return ;
	pivot = s_partition(_base, start, end);
	qsort_recursion(_base, start, pivot - 1L);
	qsort_recursion(_base, pivot + 1L, end);
}

void			quick_sort(void *_base,
					const size_t _n_el,
					const size_t _width,
					int32_t (*_cmp)(const void*, const void*))
{
	if (2 > _n_el)
		return ;
	g_width = _width;
	g_comparator = _cmp;
	qsort_recursion(_base, 0L, _n_el - 1L);
}
