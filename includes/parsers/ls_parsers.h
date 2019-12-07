/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parsers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:03:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 16:17:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_PARSERS_H
# define LS_PARSERS_H

# include "ls_s_dir.h"

int
parse_args(int ac, char **av);

void
parse_args_files_as_dir(struct s_arg *args, int32_t n);

int
parse_flags(const char *flags_str);

extern bool
parse_dir(const char *restrict path);

extern void
parse_file(const char *restrict path,
	const struct s_object *restrict obj,
	const bool is_endl);

#endif
