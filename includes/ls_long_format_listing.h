/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long_format_listing.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:52:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/01 21:58:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LONG_FORMAT_LISTING
# define LS_LONG_FORMAT_LISTING

#include <pwd.h>
#include <grp.h>

# define STR_LEN_DATE sizeof("Aug  1 05:47")
# define STR_LEN_PERMISSION sizeof("drwxrwxrwx")
# define STR_LEN_DEFAULT_FMT sizeof("%s %jd %s %s %jd %jd %s")

struct	s_long_format_helper
{
	char			*date;
	char			*permission;
	struct passwd	*pw;
	struct group	*gp;
};

# define FORMAT_HELPER typedef struct s_long_format_helper LongFormatCurrData

FORMAT_HELPER;

struct	s_long_format_spec_width
{
	size_t			st_nlink_width;
	size_t			st_size_width;
};

# define SPEC_FMT_HELPER typedef struct s_long_format_spec_width WidthSpecific

SPEC_FMT_HELPER;

#endif
