/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_long_format_listing.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:52:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 08:30:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LONG_FORMAT_LISTING_H
# define LS_LONG_FORMAT_LISTING_H

# include <pwd.h>
# include <grp.h>
# include <time.h>

# define STR_LEN_DATE        sizeof("Aug  1 05:42")
# define STR_LEN_PERMISSION  sizeof("drwxrwxrwx")
# define STR_LEN_DEFAULT_FMT sizeof("%s  %d %s  %s  %d %s %s")

# ifdef __APPLE__
#  define MY_BLCK_T typedef blkcnt_t t_blkcnt_t;
#  define MY_TIME_T typedef time_t t_time_t;
# else
#  define MY_BLCK_T typedef __blkcnt_t t_blkcnt_t;
#  define MY_TIME_T typedef __time_t t_time_t;
# endif

MY_BLCK_T;
MY_TIME_T;

struct			s_long_format_helper
{
	char	*date;
	char	*permission;
	char	*pw_name;
	char	*gr_name;
};

# define FORMAT_HELPER typedef struct s_long_format_helper LongFormatCurrData

FORMAT_HELPER;

struct			s_long_format_spec_width
{
	size_t	st_nlink_width;
	size_t	st_size_width;
};

# define SPEC_FMT_HELPER typedef struct s_long_format_spec_width WidthSpecific

SPEC_FMT_HELPER;

WidthSpecific	precalc_output(size_t const n_objs,
					InDirObject const *const objs,
					t_blkcnt_t *const total);
char			*prepare_output_fmtstr(WidthSpecific const ws);

#endif
