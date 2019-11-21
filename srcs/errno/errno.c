/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:06:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:21:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void
	*ls_errno_msg(const char *restrict const file_name,
				const char *restrict const fn_name)
{
	ft_printf("ft_ls: %s[%s]: %s\n", file_name, fn_name, strerror(errno));
	return (NULL);
}
