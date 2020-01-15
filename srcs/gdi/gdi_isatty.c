/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdi_isatty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:48 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:07:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline int32_t	*gdi_isatty_get_ptr(void)
{
	static int32_t	isatty_ret;

	return (&isatty_ret);
}

inline void		gdi_isatty_value_init(void)
{
	if (!(*gdi_isatty_get_ptr() = isatty(fileno(stdout))))
		GDI_FLAGS_SET_BIT(BIT_1_ONE);
}
