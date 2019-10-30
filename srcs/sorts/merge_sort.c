/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:39:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/30 16:00:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_fn_comparator	g_fn_comparator = NULL;

static void	s_objscpy(InDirObject *dst, InDirObject *src,
				int32_t begin, int32_t end)
{
	while (end > begin)
	{
		dst[begin] = src[begin];
		++begin;
	}
}

static void	s_topdown_merge(InDirObject *a, InDirObject *b,
				int32_t begin, int32_t middle, int32_t end)
{
	int32_t	i;
	int32_t	j;
	int32_t	k;
	int32_t cmp;

	i = begin;
	j = middle;
	k = begin;
	cmp = 0L;
	while (end > k)
	{
		cmp = g_fn_comparator(&a[i], &a[j]);
		if (middle > i && (end <= j || 0L <= cmp))
			b[k] = a[i++];
		else
			b[k] = a[j++];
		++k;
	}
}

static void	s_topdown_split_merge(InDirObject *b, InDirObject *a,
				int32_t begin, int32_t end)
{
	int32_t	middle;

	if (2 > end - begin)
		return ;
	middle = (end + begin) / 2;
	s_topdown_split_merge(a, b, begin, middle);
	s_topdown_split_merge(a, b, middle, end);
	s_topdown_merge(b, a, begin, middle, end);
}

void	merge_sort(InDirObject *objs, int32_t in_dir_objs, t_fn_comparator cmp)
{
	InDirObject	*_objs;

	g_fn_comparator = cmp;
	_objs = (InDirObject*)ft_memalloc(sizeof(InDirObject) * in_dir_objs);
	s_objscpy(_objs, objs, 0UL, in_dir_objs);
	s_topdown_split_merge(_objs, objs, 0UL, in_dir_objs);
}
