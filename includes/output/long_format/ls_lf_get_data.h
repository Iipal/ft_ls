/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lf_get_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:04:15 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:56:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LF_GET_DATA_H
# define LS_LF_GET_DATA_H

# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdint.h>

# include "ls_types.h"
# include "ls_structs.h"

# define STR_LEN_DATE        sizeof("Aug  1 05:42 2019      ")
# define STR_LEN_PERMISSION  sizeof("drwxrwxrwx     ")
# define STR_LEN_DEVICE      sizeof("1111,1111      ")
# define TIME_HALF_YEAR      15768000

extern char
*plf_get_date(char *restrict dst, const struct s_stat *restrict st);

extern char
*plf_get_permission(char *restrict perm_str, const mode_t st_mode_perm);

extern char
*plf_get_dev_info(char *restrict dst, struct s_stat *restrict st);

extern void
plf_get_link(const char *restrict file);

extern char
*plf_get_fmt_str(const size_t size_t,
	const struct s_object *restrict objs,
	t_blkcnt_t *restrict total);

#endif
