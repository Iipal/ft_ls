/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_isdir_args_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:39:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 20:54:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int32_t	sort_isdir_args_cmp(const void *a, const void *b)
{
	return (((struct s_arg*)a)->is_dir - ((struct s_arg*)b)->is_dir);
}
