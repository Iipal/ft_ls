/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_comparators.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:55:27 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 16:40:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_COMPARATORS_H
# define LS_COMPARATORS_H

# include <sys/types.h>

int64_t
sort_ascii_objects_cmp(const void *a, const void *b);

int64_t
sort_ascii_tabs_cmp(const void *a, const void *b);

int64_t
sort_ascii_args_cmp(const void *a, const void *b);

int64_t
sort_isdir_args_cmp(const void *a, const void *b);

int64_t
sort_time_objects_cmp(const void *a, const void *b);

int64_t
sort_size_objects_cmp(const void *a, const void *b);

#endif
