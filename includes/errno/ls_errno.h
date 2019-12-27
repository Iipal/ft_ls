/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/28 01:33:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_ERRNO_H
# define LS_ERRNO_H

# ifdef PFUNC
#  undef PFUNC
# endif

# define PFUNC __PRETTY_FUNCTION__
# define LS_ASSERT(expr) \
	((expr) ? (void)0 : ls_errno_exit(__FILE__, PFUNC, __LINE__, #expr))
# define LS_ASSERT_MGS(expr, msg) \
	((expr) ? (void)0 : ls_errno_exit(__FILE__, PFUNC, __LINE__, msg))

extern void __attribute__((noreturn))
ls_errno_exit(const char *restrict const file_name,
			const char *restrict const fn_name,
			const int32_t fn_line,
			const char *restrict const err_msg);

#endif
