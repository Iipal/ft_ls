/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:14:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/22 11:37:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_free(Environment **env)
{
	size_t	i;

	i = ~0ULL;
	if (*env)
	{
		if ((*env)->sorted_av)
		{
			while ((*env)->ac > ++i)
				FREE((*env)->sorted_av[i], free);
			FREE((*env)->sorted_av, free);
		}
		FREE(*env, free);
	}
}
