/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdi_dbuf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:12:49 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:14:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline char	*gdi_dbuf_get_ptr(void)
{
	static char	data_buff[GDI_DBUF_SIZE];

	return (data_buff);
}
