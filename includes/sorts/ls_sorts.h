/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:54:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 19:47:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SORTS_H
# define LS_SORTS_H

# include "ls_comparators.h"

/*
** If n_el less than 10, that function will val i_sort() if not - q_sort().
*/
extern void
choose_sort(void *restrict base,
	size_t n_el,
	size_t width,
	int32_t (*comparator)(const void*, const void*));

/*
** quick sort
*/
extern void
q_sort(void *base,
	const size_t n_el,
	const size_t width,
	int32_t (*comparator)(const void*, const void*));

/*
** insertion sort
*/
extern void
i_sort(void *base,
	const size_t n_el,
	const size_t width,
	int32_t (*comparator)(const void*, const void*));

#endif
