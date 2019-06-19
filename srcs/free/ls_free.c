/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:14:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/19 14:48:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_free(Environment **env)
{
	size_t	i;

	i = ~0ULL;
	if (*env)
	{
		while ((*env)->ac > ++i)
			FREE((*env)->sorted_av[i], free);
		FREE((*env)->sorted_av, free);
	}
	FREE(*env, free);
}
