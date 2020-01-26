/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parsers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:03:17 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:52:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_PARSERS_H
# define LS_PARSERS_H

# include "ls_structs.h"

extern int
parse_args(struct s_arg_av *restrict const a);

extern void
parse_args_files_as_dir(struct s_arg_obj *args, size_t n);

extern int
parse_flags(struct s_arg_av *restrict const a);

extern bool
parse_dir(const char *restrict path);

extern void
parse_file(const char *restrict path,
	const struct s_object *restrict obj,
	const bool is_endl);

#endif
