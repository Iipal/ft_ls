/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:52:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 14:13:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LF_H
# define LS_LF_H

# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdint.h>

# include "ls_structs.h"
# include "ls_types.h"

# define STR_LEN_DATE        sizeof("Aug  1 05:42 2019")
# define STR_LEN_PERMISSION  sizeof("drwxrwxrwx")
# define STR_LEN_DEVICE      sizeof("1111,1111")
# define STR_LEN_DEFAULT_FMT sizeof("%s%c %d %-s  %-s  %s %s %s")
# define TIME_HALF_YEAR      15768000

/*
** PLF - Print Long Format
*/
void
plf(const int32_t n_objs, const struct s_object *restrict objs);

extern void
plf_obj(char *restrict fmt_str,
	const char *restrict path,
	const struct s_object *restrict obj);

extern char
*plf_get_date(char *restrict dst, const struct stat *restrict st);

extern char
*plf_get_permission(char *restrict perm_str, const mode_t st_mode_perm);

extern char
*plf_get_dev_info(char *dst, struct stat *restrict st);

extern char
*plf_get_fmt_str(const int32_t n_objs,
	const struct s_object *restrict objs,
	t_blkcnt_t *restrict total);

#endif
