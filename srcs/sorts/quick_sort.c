/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/11 18:17:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <immintrin.h>

static size_t	g_qs_width = 0UL;
static uint8_t	*g_qs_base = NULL;
static int32_t	(*g_qs_comparator)(const void*, const void*) = NULL;

static ssize_t	s_sort_partition(register const __v2di ip)
{
	static uint8_t	*pivot;
	register __v2di	i;

	i = (__v2di) { ip[0] - 1L, ip[0] - 1L };
	pivot = g_qs_base + (ip[1] * g_qs_width);
	while (ip[1] > ++i[1])
		if (0 > g_qs_comparator(g_qs_base + (i[1] * g_qs_width), pivot))
			ft_memswap(g_qs_base + (++i[0] * g_qs_width),
				g_qs_base + (i[1] * g_qs_width), g_qs_width);
	ft_memswap(g_qs_base + (++i[0] * g_qs_width),
		g_qs_base + (ip[1] * g_qs_width), g_qs_width);
	return (i[0]);
}

static void		s_qs_recursion(register const ssize_t start,
					register const ssize_t end)
{
	ssize_t	pivot;

	if (start >= end)
		return ;
	pivot = s_sort_partition((__v2di) { start, end });
	s_qs_recursion(start, pivot - 1L);
	s_qs_recursion(pivot + 1L, end);
}

void			quick_sort(void *base,
					const size_t n_el,
					const size_t width,
					int32_t (*comparator)(const void*, const void*))
{
	if (2 > n_el)
		return ;
	g_qs_base = base;
	g_qs_width = width;
	g_qs_comparator = comparator;
	s_qs_recursion(0L, n_el - 1L);
}
