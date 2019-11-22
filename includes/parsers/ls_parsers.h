/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parsers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:03:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:04:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_PARSERS_H
# define LS_PARSERS_H

# include <stdbool.h>

# include "ls_s_object.h"

int
parse_args(int ac, char **av);

bool
parse_flags(const char *flags_str);

extern bool
parse_dir(const char *restrict path);
extern void
parse_file(const char *restrict path, const struct s_object *restrict obj);

#endif
