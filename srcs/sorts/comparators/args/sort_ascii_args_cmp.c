/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_args_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:22:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 17:14:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int64_t	sort_ascii_args_cmp(const void *restrict a, const void *restrict b)
{
	return ((int64_t)ft_strcmp(((const struct s_arg*)a)->path,
							((const struct s_arg*)b)->path));
}
