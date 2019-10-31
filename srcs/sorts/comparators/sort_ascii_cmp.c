/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:27:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/31 14:36:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_ascii_cmp(void const *a, void const *b)
{
	int32_t const	cmp = ft_strcmp((char const*)b, (char const*)a);

	return cmp;
}
