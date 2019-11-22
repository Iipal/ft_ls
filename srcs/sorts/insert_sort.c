/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:52:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 11:06:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	g_is_width = 0UL;
static void		*g_is_base = NULL;
static int32_t	(*g_is_comparator)(const void*, const void*) = NULL;

void	i_sort(void *base,
			const size_t n_el,
			const size_t width,
			int32_t (*comparator)(const void*, const void*))
{
	t_s2sl	i;
	void	*key;

	if (2UL > n_el)
		return ;
	i.x = 0L;
	key = ft_memalloc(width);
	while (n_el > ++i.x)
	{
		ft_memcpy(key, base + (i.x * width), width);
		i.y = i.x - 1L;
		while (0 <= i.y)
		{
			if (0 >= comparator(base + (i.y * width), key))
				break ;
			ft_memmove(base + ((i.y + 1L) * width),
						base + (i.y * width), width);
			--i.y;
		}
		ft_memmove(base + ((i.y + 1) * width), key, width);
	}
	ft_memdel(&key);
}
