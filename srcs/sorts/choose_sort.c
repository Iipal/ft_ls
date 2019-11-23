/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:30:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 19:32:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ls.h"

inline void	choose_sort(void *restrict base,
				size_t n_el,
				size_t width,
				int32_t (*comparator)(const void*, const void*))
{
	if (2 > n_el)
		return ;
	if (10 >= n_el)
		i_sort(base, n_el, width, comparator);
	else
		q_sort(base, n_el, width, comparator);
}
