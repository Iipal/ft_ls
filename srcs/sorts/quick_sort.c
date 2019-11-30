/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 12:58:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	g_qs_width = 0UL;
static void		*g_qs_base = NULL;
static int32_t	(*g_qs_comparator)(const void*, const void*) = NULL;

static ssize_t	s_qs_partition(register const t_s2sl pi)
{
	t_s2sl	i;
	void	*pivot;

	i = (t_s2sl) { pi.x - 1L, pi.x - 1L};
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

static void		s_qs_recursive(t_s2sl pi)
{
	ssize_t	pivot;

	if (pi.x > pi.y)
		return ;
	pivot = s_qs_partition(pi);
	s_qs_recursive((t_s2sl) { pi.x, pivot - 1L });
	s_qs_recursive((t_s2sl) { pivot + 1L, pi.y });
}

static void		s_qs_iterative(t_s2sl pi)
{
	ssize_t	pivot;
	ssize_t	stack[pi.y - pi.x + 1L];
	ssize_t	top = -1L;

	stack[++top] = pi.x;
	stack[++top] = pi.y;
	while (0 <= top)
	{
		pi.y = stack[top--];
		pi.x = stack[top--];
		pivot = s_qs_partition(pi);
		if (pivot - 1L > pi.x)
		{
			stack[++top] = pi.x;
			stack[++top] = pivot - 1L;
		}
		if (pivot + 1L < pi.y)
		{
			stack[++top] = pivot + 1L;
			stack[++top] = pi.y;
		}
	}
}

inline void		q_sort(void *base,
					const size_t n_el,
					const size_t width,
					int32_t (*comparator)(const void*, const void*))
{
	g_qs_base = base;
	g_qs_width = width;
	g_qs_comparator = comparator;
	if (500UL <= n_el)
		s_qs_recursive((t_s2sl) { 0L, n_el - 1L });
	else
		s_qs_iterative((t_s2sl) { 0L, n_el - 1L });
}
