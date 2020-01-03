/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:06:46 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/03 20:23:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

#if defined (LS_DEBUG_MSG) || defined (FT_LS_DEBUG)

inline void __attribute__((noreturn))
	ls_errno_exit(const char *restrict const file_name,
				const char *restrict const fn_name,
				const size_t fn_line,
				const char *restrict const err_msg)
{
	ft_fprintf(stderr, "%s[%3zu]: %s\n\t'%s': %s\n",
		file_name, fn_line, fn_name, err_msg, strerror(errno));
	_Exit(1);
}

#else

inline void __attribute__((noreturn))
	ls_errno_exit(const char *restrict const file_name,
				const char *restrict const fn_name,
				const size_t fn_line,
				const char *restrict const err_msg)
{
	(void)file_name;
	(void)fn_name;
	(void)fn_line;
	ft_fprintf(stderr, "ft_ls: %s: %s\n", err_msg, strerror(errno));
	_Exit(1);
}

#endif
