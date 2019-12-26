/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:52:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/26 02:09:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	i_sort(void *restrict base,
			const size_t n_el,
			const size_t width,
			int64_t (*comparator)(const void*, const void*))
{
	u_char *restrict	c_base;
	t_s2sl				i;
	void				*key;

	if (2UL > n_el)
		return ;
	c_base = (u_char*)base;
	i.x = 0L;
	key = ft_memalloc(width);
	while ((long)n_el > ++i.x)
	{
		ft_memcpy(key, c_base + (i.x * width), width);
		i.y = i.x - 1L;
		while (0 <= i.y)
		{
			if (0 >= comparator(c_base + (i.y * width), key))
				break ;
			ft_memmove(c_base + ((i.y + 1L) * width),
						c_base + (i.y * width), width);
			--i.y;
		}
		ft_memmove(c_base + ((i.y + 1) * width), key, width);
	}
	ft_memdel(&key);
}
