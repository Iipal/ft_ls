/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_lf_spec_width.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:51:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 12:51:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_S_LF_SPEC_WIDTH_H
# define LS_S_LF_SPEC_WIDTH_H

# include <sys/types.h>

struct	s_lf_spec_width
{
	size_t	st_nlnk_w;
	size_t	st_size_w;
	size_t	pw_name_w;
	size_t	gr_name_w;
};

#endif
