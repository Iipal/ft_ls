/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdi_maxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:04:38 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:06:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline size_t	*gdi_maxlen_get_ptr(void)
{
	static size_t	maxlen;

	return (&maxlen);
}

inline void		gdi_maxlen_cmp(size_t len)
{
	if (GDI_MAXLEN_GET_VALUE() < len)
		GDI_MAXLEN_GET_VALUE() = len;
}
