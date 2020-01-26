/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:52:09 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:53:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LF_H
# define LS_LF_H

# include "ls_lf_get_data.h"

/*
** PLF - Print Long Format
*/
extern void
plf(const size_t n_objs, const struct s_object *restrict objs);

extern void
plf_obj(char *restrict fmt_str,
	const char *restrict path,
	const struct s_object *restrict obj);

#endif
