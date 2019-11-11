/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/11 14:41:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <immintrin.h>

static size_t	g_width = 0UL;
static uint8_t	*g_base = NULL;
static int		(*g_comparator)(const void*, const void*) = NULL;

static ssize_t	s_partition(register const ssize_t start,
					register const ssize_t end)
{
	ssize_t	j;
	ssize_t	i;
	uint8_t	*pivot;

	j = start - 1L;
	i = start - 1L;
	pivot = (uint8_t*)ft_memdup(g_base + (end * g_width), g_width);
	while (end > ++j)
		if (0 < g_comparator(g_base + (j * g_width), pivot))
			ft_memswap(g_base + (++i * g_width),
				g_base + (j * g_width), g_width);
	ft_memswap(g_base + (++i * g_width), g_base + (end * g_width), g_width);
	ft_memdel((void**)&pivot);
	return (i);
}

static void		qsort_recursion(register const ssize_t start,
					register const ssize_t end)
{
	ssize_t	pivot;

	if (start >= end)
		return ;
	pivot = s_partition(start, end);
	qsort_recursion(start, pivot - 1L);
	qsort_recursion(pivot + 1L, end);
}

void			quick_sort(void *_base,
					const size_t _n_el,
					const size_t _width,
					int32_t (*_cmp)(const void*, const void*))
{
	if (2 > _n_el)
		return ;
	g_base = _base;
	g_width = _width;
	g_comparator = _cmp;
	qsort_recursion(0L, _n_el - 1L);
}
