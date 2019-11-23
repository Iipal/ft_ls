/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:06:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 11:17:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void
	*ls_errno_msg(const char *restrict const file_name,
				const char *restrict const fn_name,
				const int32_t fn_line,
				const char *restrict const err_msg)
{
	ft_printf("ft_ls: (%s[%s:%d]) %s: %s\n",
		file_name, fn_name, fn_line, err_msg, strerror(errno));
	return (NULL);
}
