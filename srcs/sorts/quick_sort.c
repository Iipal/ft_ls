/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/04 20:38:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <immintrin.h>

static size_t	g_width = 0UL;
static int		(*g_comparator)(void const*, void const*) = NULL;

static void	qsort_recursion(void *_base, ssize_t const m, ssize_t const n)
{
	void	*key;
	ssize_t	i;
	ssize_t	j;

	if (m >= n)
		return ;
	ft_memswap(_base + (m * g_width),
		_base + (((m + n) / 2) * g_width), g_width);
	key = ft_memdup(_base + (m * g_width), g_width);
	i = m + 1;
	j = n;
	while (i <= j)
	{
		while (n >= i && 0 >= g_comparator(_base + (i * g_width), key))
			++i;
		while (m <= j && 0 < g_comparator(_base + (j * g_width), key))
			--j;
		if (i < j)
			ft_memswap(_base + (i * g_width), _base + (j * g_width), g_width);
	}
	ft_memswap(_base + (m * g_width), _base + (j * g_width), g_width);
	ft_memdel(&key);
	qsort_recursion(_base, m, j - 1);
	qsort_recursion(_base, j + 1, n);
}

void	quick_sort(void *_base, size_t const _n_el, size_t const _width,
				int32_t (*_cmp)(void const*, void const*))
{
	if (2 > _n_el)
		return ;
	g_width = _width;
	g_comparator = _cmp;
	qsort_recursion(_base, 0UL, _n_el - 1UL);
}
