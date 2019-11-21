/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:45:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 11:31:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *restrict dest,
			const char *restrict str,
			size_t len)
{
	size_t	j;
	size_t	i;

	i = 0UL;
	j = ~0UL;
	while (len > i)
		if (!str[i])
			dest[++j] = 0;
		else
			dest[++j] = str[i++];
	return (dest);
}
