/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:30:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 16:39:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	choose_sort(void *restrict base,
				size_t n_el,
				size_t width,
				int64_t (*comparator)(const void*, const void*))
{
	if (2UL > n_el)
		return ;
	if (10UL >= n_el || 500UL <= n_el)
		i_sort(base, n_el, width, comparator);
	else
		q_sort(base, n_el, width, comparator);
}
