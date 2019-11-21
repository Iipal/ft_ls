/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 16:42:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_INTERNAL_H
# define PF_INTERNAL_H

# include <stddef.h>
# include <limits.h>
# include <inttypes.h>

# include "libft.h"

/*
** global variables:
*/
# include "pf_global_vars.h"

/*
** Bit mask for each flag specifications:
*/
# include "pf_bits_masks.h"

/*
** Errno:
*/
# include "pf_errno.h"

extern bool
pf_flag_parser(const char *restrict format);

extern bool
pf_decimal(va_list *ap);
extern bool
pf_string(va_list *ap);
extern bool
pf_address(va_list *ap);
extern bool
pf_octal(va_list *ap);

extern char
*pf_get_signed_data(va_list *ap);
extern char
*pf_get_unsigned_data(va_list *ap);

#endif
