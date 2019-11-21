/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_signed_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:40:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/20 00:06:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internal.h"

inline char	*pf_get_signed_data(va_list *ap)
{
	if (!g_flag_type_mask
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_H)
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_HH))
		return (ft_itoa(va_arg(*ap, int)));
	else if (g_flag_type_mask)
		return (ft_ltoa(va_arg(*ap, long)));
	return (NULL);
}
