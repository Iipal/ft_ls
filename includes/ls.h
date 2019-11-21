/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 21:28:19 by tmaluh           ###   ########.fr       */
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
#  define MY_BLCK_T typedef blkcnt_t t_blkcnt_t
#  define MY_TIME_T typedef time_t t_time_t
# else
#  define MY_BLCK_T typedef __blkcnt_t t_blkcnt_t
#  define MY_TIME_T typedef __time_t t_time_t
# endif

# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <math.h>

MY_BLCK_T;
MY_TIME_T;

extern int32_t	g_flags;
extern char		*g_src_path;
extern size_t	g_max_name_len;
extern s2si		g_win_size;
extern int		g_main_ret;

/*
**	Get terminal window size;
*/
extern bool			get_term_win_size(void);

/*
** Start parsing arguments:
*/
int					parse_args(int ac, char **av);

/*
** parsing data and output
*/
bool				parse_flags(const char *flags_str);

bool				parse_dir(const char *restrict path);
void				parse_file(const char *restrict path,
						const InDirObject *restrict obj);

void				parse_flags_output(const char *restrict path,
						const CurrDir *restrict cd);

/*
** initialize:
*/
CurrDir				*init_only_file(const char *restrict path);
CurrDir				*init_curr_dir(const char *path,
						const bool force_open_dir);
extern InDirObject	*init_curr_in_dir_obj(InDirObject *restrict dst,
						const struct stat *restrict stat,
						const struct dirent *restrict dirent,
						const char *restrict filename);

/*
** initialize checks:
*/
bool				init_lstat_check(const char *restrict path,
						struct stat *restrict buff);
bool				init_lstat_check_no_errno(const char *restrict path,
						struct stat *restrict buff);

/*
** initialize utils:
*/
struct dirent		*dup_dirent(const struct dirent *restrict src);
struct stat			*dup_stat(const struct stat *restrict src);

/*
** sort callback-comparators
*/
int32_t				sort_ascii_dirents_cmp(const void *a, const void *b);
int32_t				sort_ascii_tabs_cmp(const void *a, const void *b);
int32_t				sort_ascii_args_cmp(const void *a, const void *b);
int32_t				sort_isdir_args_cmp(const void *a, const void *b);
int32_t				sort_time_stats_cmp(const void *a, const void *b);

/*
** quick sort
*/
extern void			q_sort(void *base,
						const size_t n_el,
						const size_t width,
						int32_t (*comparator)(const void*, const void*));

/*
** PLF - Print Long Format
*/
void				plf_objs(const int32_t n_objs,
						const InDirObject *restrict objs);
void				plf_obj(char *restrict fmt_str,
						const char *restrict path,
						const InDirObject *restrict obj,
						const bool is_free_fmt);

char				*plf_get_date(char *restrict date_str,
						const t_time_t date_time);
char				*plf_get_permission(char *restrict perm_str,
						const mode_t st_mode_perm);

/*
** PDF - Print Default Format
*/
void				pdf_objs(const int32_t n_objs,
						const InDirObject *const objs);

/*
** free
*/
void				*free_curr_dir(CurrDir **curr_dir);
void				*free_curr_in_dir_obj(InDirObject *obj);

#endif
