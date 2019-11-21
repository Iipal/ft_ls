/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_str_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:55:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 16:42:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internal.h"

inline void __attribute__((__overloadable__))
	pf_put_str_buf(void)
{
	size_t	i;

	i = ~0UL;
	while (g_data_len > ++i)
		pf_put_ch_buf(g_data_ptr[i]);
}

inline void __attribute__((__overloadable__))
	pf_put_str_buf(size_t len)
{
	size_t	i;

	i = ~0UL;
	if (len > g_data_len)
		len = g_data_len;
	while (len > ++i)
		pf_put_ch_buf(g_data_ptr[i]);
}

inline void __attribute__((__overloadable__))
	pf_put_str_buf(const char *restrict str, size_t len)
{
	size_t	i;

	i = ~0UL;
	while (len > ++i)
		pf_put_ch_buf(str[i]);
}
