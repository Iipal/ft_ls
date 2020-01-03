/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_isdir_args_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:39:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 17:14:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int64_t	sort_isdir_args_cmp(const void *restrict a, const void *restrict b)
{
	return ((int64_t)(((struct s_arg_obj*)a)->is_dir - ((struct s_arg_obj*)b)->is_dir));
}
