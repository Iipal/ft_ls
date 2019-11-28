/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:30:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 19:43:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	choose_sort(void *restrict base,
				size_t n_el,
				size_t width,
				int32_t (*comparator)(const void*, const void*))
{
	void	*bt_arr[15];
	size_t	bt_size;

	if (2 > n_el)
		return ;
	if (3000UL <= n_el)
		bt_size = backtrace(bt_arr, 15);
	if (10UL >= n_el || bt_size >= 15UL || 3000UL <= n_el)
		i_sort(base, n_el, width, comparator);
	else
		q_sort(base, n_el, width, comparator);
}
