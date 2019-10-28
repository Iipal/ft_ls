/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 08:34:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	s_find_max_name_len(size_t const n_objs,
					InDirObject const *const objs)
{
	size_t	curr_len;
	size_t	max_len;
	size_t	i;

	i = ~0ULL;
	max_len = ft_strlen((*objs).dirent->d_name);
	while (n_objs > ++i)
	{
		curr_len = ft_strlen(objs[i].dirent->d_name);
		if (max_len < curr_len)
			max_len = curr_len;
	}
	return (max_len);
}

void			print_default_format(size_t const n_objs,
					InDirObject const *const objs)
{
	size_t	max_obj_name_len;
	size_t	i;

	i = ~0ULL;
	max_obj_name_len = s_find_max_name_len(n_objs, objs);
	while (n_objs > ++i)
	{
		ft_printf("%s", objs[i].dirent->d_name);
		if (!IS_BIT(g_flags, BIT_1_ONE))
			ft_putnchar(' ', max_obj_name_len
				- ft_strlen(objs[i].dirent->d_name));
		if (n_objs - 1 != i)
		{
			if (IS_BIT(g_flags, BIT_1_ONE))
				ft_putchar('\n');
			else
				ft_putchar(' ');
		}
	}
	ft_putchar('\n');
}
