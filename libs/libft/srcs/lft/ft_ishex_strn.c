/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex_strn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:40:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 09:54:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_ishex_strn(const char *restrict s, size_t n)
{
	size_t		i;
	const char	*str = (const char*)s;
	const char	valid_hex[] = "0123456789abcdef";

	while (n--)
	{
		i = ~0ULL;
		while (valid_hex[++i])
			if (F_TOLOWER(*str) == valid_hex[i])
				break ;
		if (F_TOLOWER(*str++) != valid_hex[i])
			return (false);
	}
	return (true);
}
