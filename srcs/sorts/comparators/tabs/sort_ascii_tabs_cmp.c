/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_tabs_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:40:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 17:15:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int64_t	sort_ascii_tabs_cmp(const void *restrict a, const void *restrict b)
{
	return ((int64_t)ft_strcmp(*(const char**)a, *(const char**)b));
}
