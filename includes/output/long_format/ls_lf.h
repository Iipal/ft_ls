/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:52:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 18:40:46 by tmaluh           ###   ########.fr       */
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

# define STR_LEN_DATE        sizeof("Aug  1 05:42")
# define STR_LEN_PERMISSION  sizeof("drwxrwxrwx")
# define STR_LEN_DEFAULT_FMT sizeof("%s%c %d %-s  %-s  %d %s %s")

/*
** PLF - Print Long Format
*/
void
plf(const int32_t n_objs, const struct s_object *restrict objs);

extern void
plf_obj(char *restrict fmt_str,
	const char *restrict path,
	const struct s_object *restrict obj,
	const bool is_free_fmt);

extern char
*plf_get_date(char *restrict date_str, const t_time_t file_time);

extern char
*plf_get_permission(char *restrict perm_str, const mode_t st_mode_perm);

/*
** Preparing output format string for LF output.
*/
struct s_lf_spec_width
plf_width_spec(const uint32_t n_objs,
	const struct s_object *restrict objs,
	t_blkcnt_t *restrict total);

char
*plf_fmt_str(const struct s_lf_spec_width ws);

#endif
