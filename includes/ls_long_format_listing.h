/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long_format_listing.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:52:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 18:51:20 by tmaluh           ###   ########.fr       */
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
# define STR_LEN_DEFAULT_FMT sizeof("%s  %d %s  %s  %d %s %s")

struct			s_lf_spec_width
{
	int32_t	st_nlink_width;
	int32_t	st_size_width;
};

# define SPEC_FMT_HELPER typedef struct s_lf_spec_width WidthSpecific

SPEC_FMT_HELPER;

WidthSpecific	plf_width_spec(const uint32_t n_objs,
					const InDirObject *restrict objs,
					t_blkcnt_t *restrict total);
char			*plf_fmt_str(const WidthSpecific ws);

#endif
