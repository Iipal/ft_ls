/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:30:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 21:34:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	choose_sort(void *restrict base,
				size_t n_el,
				size_t width,
				int32_t (*comparator)(const void*, const void*))
{
	void	*bt_arr[16] = { NULL };
	int		bt_size;

	bt_size = 0;
	if (2UL > n_el)
		return ;
	if (1000UL <= n_el)
		bt_size = backtrace(bt_arr, 15);
	if (10UL >= n_el || bt_size >= 15 || 1000UL <= n_el)
		i_sort(base, n_el, width, comparator);
	else
		q_sort(base, n_el, width, comparator);
}
