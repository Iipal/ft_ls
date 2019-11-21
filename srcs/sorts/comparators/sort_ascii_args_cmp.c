/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii_args_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:22:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 21:22:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_ascii_args_cmp(const void *a, const void *b)
{
	return (ft_strncmp(((const struct s_arg*)a)->path,
						((const struct s_arg*)b)->path,
						((const struct s_arg*)a)->path_len));
}
