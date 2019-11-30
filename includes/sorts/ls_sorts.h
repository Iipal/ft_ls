/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sorts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:54:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 12:49:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SORTS_H
# define LS_SORTS_H

# include "ls_comparators.h"

/*
** "smart" sort function select.
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
