/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 11:03:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# define _GNU_SOURCE

# include "libft.h"
# include "ft_printf.h"

# include "ls_errno.h"
# include "ls_flags.h"
# include "ls_structs.h"
# include "ls_utils.h"

# ifdef __APPLE__
typedef blkcnt_t	t_blkcnt_t;
typedef time_t	t_time_t;
# else
typedef __blkcnt_t	t_blkcnt_t;
typedef __time_t	t_time_t;
# endif

# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <math.h>

extern int32_t	g_flags;
extern char		*g_src_path;
extern size_t	g_max_name_len;
extern t_s2si	g_win_size;
extern int		g_main_ret;

/*
**	Get terminal window size;
*/
extern bool
get_term_win_size(void);

/*
** Start parsing arguments:
*/
int
parse_args(int ac, char **av);

/*
** parsing data and output
*/
bool
parse_flags(const char *flags_str);

extern bool
parse_dir(const char *restrict path);
extern void
parse_file(const char *restrict path, const struct s_object *restrict obj);

void
output(const char *restrict path, const struct s_dir *restrict cd);

/*
** initialize:
*/
extern struct s_dir
*init_file(const char *restrict path);

struct s_dir
*init_dir(const char *path, const bool force_open_dir);

extern struct s_object
*init_dir_obj(struct s_object *restrict dst,
	const struct stat *restrict stat,
	const struct dirent *restrict dirent,
	const char *restrict filename);

/*
** initialize checks:
*/
extern bool
init_lstat_check(const char *restrict path, struct stat *restrict buff);

extern bool
init_lstat_check_no_errno(const char *restrict path,
	struct stat *restrict buff);

/*
** initialize utils:
*/
extern struct dirent
*dup_dirent(const struct dirent *restrict src);

extern struct stat
*dup_stat(const struct stat *restrict src);

/*
** sort callback-comparators
*/
int32_t
sort_ascii_dirents_cmp(const void *a, const void *b);

int32_t
sort_ascii_tabs_cmp(const void *a, const void *b);

int32_t
sort_ascii_args_cmp(const void *a, const void *b);

int32_t
sort_isdir_args_cmp(const void *a, const void *b);

int32_t
sort_time_stats_cmp(const void *a, const void *b);

/*
** quick sort
*/
extern void
q_sort(void *base,
	const size_t n_el,
	const size_t width,
	int32_t (*comparator)(const void*, const void*));

/*
** insertion sort
*/
extern void
i_sort(void *base,
	const size_t n_el,
	const size_t width,
	int32_t (*comparator)(const void*, const void*));

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
*plf_get_date(char *restrict date_str, const t_time_t date_time);

extern char
*plf_get_permission(char *restrict perm_str, const mode_t st_mode_perm);

/*
** PDF - Print Default Format
*/
void
pdf(const int32_t n_objs, const struct s_object *const objs);

/*
** free
*/
void
*free_dir(struct s_dir **curr_dir);

extern void
*free_dir_obj(struct s_object *obj);

#endif
