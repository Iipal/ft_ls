/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:22:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_ERRNO_H
# define LS_ERRNO_H

extern void
*ls_errno_msg(const char *restrict const file_name,
			const char *restrict const fn_name);

#endif
