/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:52:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:05:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LF_H
# define LS_LF_H

# include "ls_lf_get_data.h"

/*
** PLF - Print Long Format
*/
void
plf(const int32_t n_objs, const struct s_object *restrict objs);

extern void
plf_obj(char *restrict fmt_str,
	const char *restrict path,
	const struct s_object *restrict obj);

#endif
