/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_valid_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:56:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 19:13:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	*free_valid_args(char **args, int max)
{
	int	i;

	i = -1;
	if (max && args)
	{
		while (max > ++i)
			FREE(args[i], free);
		FREE(args, free);
	}
	return (NULL);
}
