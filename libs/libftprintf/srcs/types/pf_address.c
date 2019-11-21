/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/19 23:22:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internal.h"

inline bool	pf_address(va_list *ap)
{
	intptr_t	addr;
	ssize_t		width;

	addr = (intptr_t)va_arg(*ap, void*);
	if (!(g_data_ptr = ft_ltoa_base(addr, 16)))
		return (false);
	g_data_len = ft_strlen(g_data_ptr);
	width = (ssize_t)g_flag_width - (ssize_t)(g_data_len + 2L);
	if (0 < width && !IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_MINUS))
		pf_put_ch_buf(' ', (size_t)width);
	pf_put_str_buf("0x", sizeof("0x"));
	pf_put_str_buf();
	if (0 < width && IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_MINUS))
		pf_put_ch_buf(' ', (size_t)width);
	ft_strdel(&g_data_ptr);
	return (true);
}
