/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:06:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 22:45:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

# if defined (LS_DEBUG_MSG) || defined (DEBUG)

inline void
	*ls_errno_msg(const char *restrict const file_name,
				const char *restrict const fn_name,
				const int32_t fn_line,
				const char *restrict const err_msg)
{
	ft_dprintf(STDERR_FILENO, "ft_ls: (%s[%s:%d]) %s: %s\n",
		file_name, fn_name, fn_line, err_msg, strerror(errno));
	return (NULL);
}

# else

inline void
	*ls_errno_msg(const char *restrict const file_name,
				const char *restrict const fn_name,
				const int32_t fn_line,
				const char *restrict const err_msg)
{
	(void)file_name;
	(void)fn_name;
	(void)fn_line;
	ft_dprintf(STDERR_FILENO, "ft_ls: %s: %s\n", err_msg, strerror(errno));
	return (NULL);
}

# endif
