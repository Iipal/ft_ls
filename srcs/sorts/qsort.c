/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/12 20:20:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	g_qs_width;
static void		*g_qs_base;
int32_t			(*g_qs_comparator)(const void*, const void*);

static ssize_t	s_qs_partition(register const __v2di pi)
{
	volatile __v2di	i;
	void			*pivot;

	i = (__v2di) { pi[0] - 1L, pi[0] - 1L};
	pivot = ft_memdup(g_qs_base + (pi[1] * g_qs_width), g_qs_width);
	while (pi[1] - 1L >= ++i[1])
		if (g_qs_comparator(g_qs_base + (i[1] * g_qs_width), pivot))
			ft_memswap(g_qs_base + (++i[0] * g_qs_width),
				g_qs_base + (i[1] * g_qs_width), g_qs_width);
	ft_memswap(g_qs_base + (++i[0] * g_qs_width),
		g_qs_base + (pi[1] * g_qs_width), g_qs_width);
	free(pivot);
	return (i[0]);
}

static void	s_qs_recursive(register const __v2di pi)
{
	ssize_t	pivot;

	if (pi[0] > pi[1])
		return ;
	pivot = s_qs_partition(pi);
	s_qs_recursive((__v2di) { pi[0], pivot - 1L });
	s_qs_recursive((__v2di) { pivot + 1L, pi[1] });
}

inline void	q_sort(void *base,
				const size_t n_el,
				const size_t width,
				int32_t (*comparator)(const void*, const void*))
{
	if (2 > n_el)
		return ;
	g_qs_base = base;
	g_qs_width = width;
	g_qs_comparator = comparator;
	s_qs_recursive((__v2di) { 0, n_el - 1L });
}
