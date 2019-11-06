/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_valid_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:56:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 18:48:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	*free_valid_args(char **args, const int32_t max)
{
	int32_t	i;

	i = -1;
	if (max && args)
	{
		while (max > ++i)
			FREE(args[i], free);
		FREE(args, free);
	}
	return (NULL);
}
