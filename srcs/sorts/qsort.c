/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 21:20:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	g_qs_width;
static void		*g_qs_base;
int32_t			(*g_qs_comparator)(const void*, const void*);

static ssize_t	s_qs_partition(register const s2sl pi)
{
	register s2sl	i;
	void			*pivot;

	i = (s2sl) { pi.x - 1L, pi.x - 1L};
	pivot = ft_memdup(g_qs_base + (pi.y * g_qs_width), g_qs_width);
	while (pi.y - 1L >= ++i.y)
		if (0 >= g_qs_comparator(g_qs_base + (i.y * g_qs_width), pivot))
			ft_memswap(g_qs_base + (++i.x * g_qs_width),
				g_qs_base + (i.y * g_qs_width), g_qs_width);
	ft_memswap(g_qs_base + (++i.x * g_qs_width),
		g_qs_base + (pi.y * g_qs_width), g_qs_width);
	free(pivot);
	return (i.x);
}

static void		s_qs_recursive(register const s2sl pi)
{
	ssize_t	pivot;

	if (pi.x > pi.y)
		return ;
	pivot = s_qs_partition(pi);
	s_qs_recursive((s2sl) { pi.x, pivot - 1L });
	s_qs_recursive((s2sl) { pivot + 1L, pi.y });
}

inline void		q_sort(void *base,
					const size_t n_el,
					const size_t width,
					int32_t (*comparator)(const void*, const void*))
{
	if (2 > n_el)
		return ;
	g_qs_base = base;
	g_qs_width = width;
	g_qs_comparator = comparator;
	s_qs_recursive((s2sl) { 0, n_el - 1L });
}
