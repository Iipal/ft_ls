/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long_format_listing.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:52:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:39:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LONG_FORMAT_LISTING_H
# define LS_LONG_FORMAT_LISTING_H

# include <pwd.h>
# include <grp.h>
# include <time.h>

# include "ls.h"

# define STR_LEN_DATE        sizeof("Aug  1 05:42")
# define STR_LEN_PERMISSION  sizeof("drwxrwxrwx")
# define STR_LEN_DEFAULT_FMT sizeof("%s%c %d %-s  %-s  %d %s %s")

struct	s_lf_spec_width
{
	size_t	st_nlnk_w;
	size_t	st_size_w;
	size_t	pw_name_w;
	size_t	gr_name_w;
};

struct s_lf_spec_width
	plf_width_spec(const uint32_t n_objs,
		const struct s_object *restrict objs,
		t_blkcnt_t *restrict total);
char
	*plf_fmt_str(const struct s_lf_spec_width ws);

#endif
