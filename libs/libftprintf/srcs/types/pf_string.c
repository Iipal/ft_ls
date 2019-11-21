/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 16:44:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internal.h"

static inline void __attribute__((__always_inline__))
	s_put_str_to_buf(void)
{
	size_t	swidth;
	size_t	dwidth;

	swidth = (g_flag_width > g_data_len) ? (g_flag_width - g_data_len) : 0UL;
	dwidth = (g_data_len > g_flag_width) ? g_flag_width : g_data_len;
	if (IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_MINUS))
	{
		if (IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_DOT))
			pf_put_str_buf(dwidth);
		else
		{
			pf_put_str_buf();
			pf_put_ch_buf(' ', swidth);
		}
	}
	else
	{
		if (IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_DOT))
			pf_put_str_buf(dwidth);
		else
		{
			pf_put_ch_buf(' ', swidth);
			pf_put_str_buf();
		}
	}
}

static inline int __attribute__((__always_inline__))
	s_choose_data(va_list *ap)
{
	if ('s' == g_flag)
	{
		if (!(g_data_ptr = (char*)va_arg(*ap, char*)))
			g_data_ptr = "(null)";
	}
	else if ('%' == g_flag)
		return ('%');
	else
		return (va_arg(*ap, int));
	return (0);
}

inline bool
	pf_string(va_list *ap)
{
	static char	ch;
	static bool	is_str;

	ch = s_choose_data(ap);
	is_str = !(g_flag == 'c' || g_flag == '%');
	g_data_len = is_str ? ft_strlen(g_data_ptr) : 1UL;
	if (is_str)
		s_put_str_to_buf();
	else
		pf_put_ch_buf(ch);
	g_data_ptr = NULL;
	return (true);
}
