/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free_curr_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/18 17:30:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ls_free_curr_dir(CurrDir **cur_dir)
{
	size_t	i;

																																							i = ~0ULL;
	if (*cur_dir)
	{
		while ((*cur_dir)->in_dir_dirents > ++i)
			FREE((*cur_dir)->dirents[i], free);
		FREE((*cur_dir)->dirents, free);
		FREE((*cur_dir), free);
	}
}
