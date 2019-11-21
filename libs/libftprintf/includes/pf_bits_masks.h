/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bits_masks.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:20:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 16:42:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_BITS_MASKS_H
# define PF_BITS_MASKS_H

# include "libft_bits_macroses.h"

/*
** g_flag_spec_mask bit masks.
*/
# define PF_BIT_SPEC_MINUS (1 << 0)
# define PF_BIT_SPEC_DOT   (1 << 1)

/*
** g_flag_type_mask bit masks.
*/
# define PF_BIT_TYPE_L     (1 << 0)
# define PF_BIT_TYPE_H     (1 << 1)
# define PF_BIT_TYPE_J     (1 << 2)
# define PF_BIT_TYPE_T     (1 << 3)
# define PF_BIT_TYPE_Z     (1 << 4)
# define PF_BIT_TYPE_HH    (1 << 5)
# define PF_BIT_TYPE_LL    (1 << 6)

#endif
