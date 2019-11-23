/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 11:14:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_ERRNO_H
# define LS_ERRNO_H

extern void
*ls_errno_msg(const char *restrict const file_name,
			const char *restrict const fn_name,
			const int32_t fn_line,
			const char *restrict const err_msg);

#endif
