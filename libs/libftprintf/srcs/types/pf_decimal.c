/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:08:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/19 23:45:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internal.h"

inline bool
	pf_decimal(va_list *ap)
{
	const int	wch = IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_DOT) ? '0' : ' ';

	g_data_ptr = pf_get_signed_data(ap);
	if (!g_data_ptr)
		return (false);
	g_data_len = ft_strlen(g_data_ptr);
	if (IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_MINUS) && wch != '0')
		pf_put_str_buf();
	if (g_flag_width > g_data_len)
		pf_put_ch_buf(wch, g_flag_width - g_data_len);
	if (!IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_MINUS) || wch == '0')
		pf_put_str_buf();
	ft_strdel(&g_data_ptr);
	return (true);
}
