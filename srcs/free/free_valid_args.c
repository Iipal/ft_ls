/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_valid_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:56:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/29 16:32:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	*free_valid_args(char **args, int32_t const max)
{
	register int32_t	i;

	i = -1;
	if (max && args)
	{
		while (max > ++i)
			FREE(args[i], free);
		FREE(args, free);
	}
	return (NULL);
}
