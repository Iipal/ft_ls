/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 18:54:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include "ft_printf.h"
# include "ls_errno.h"
# include "ls_flags.h"
# include "ls_structs.h"
# include "ls_utils.h"

# ifdef __APPLE__
#  define MY_BLCK_T typedef blkcnt_t t_blkcnt_t;
#  define MY_TIME_T typedef time_t t_time_t;
# else
#  define MY_BLCK_T typedef __blkcnt_t t_blkcnt_t;
#  define MY_TIME_T typedef __time_t t_time_t;
# endif

# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>

MY_BLCK_T;
MY_TIME_T;

extern int32_t	g_flags;
extern char		*g_src_path;

bool				parse_flags(const char *flags_str);

bool				parse_dir(const char *restrict path);
void				parse_file(const char *restrict path,
						const InDirObject *restrict obj);

void				parse_flags_output(const char *restrict path,
						const CurrDir *restrict cd);

/*
** PLF - Print Long Format
*/
void				plf_objs(const uint32_t n_objs,
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
void				pdf_objs(const uint32_t n_objs,
						const InDirObject *const objs);

CurrDir				*init_only_file(const char *restrict path);
CurrDir				*init_curr_dir(const char *restrict path,
						const bool force_open_dir);
extern InDirObject	*init_curr_in_dir_obj(InDirObject *restrict dst,
						const struct stat *restrict stat,
						const struct dirent *restrict dirent);

bool				init_lstat_check(const char *restrict path,
						struct stat *restrict buff);
bool				init_lstat_check_no_errno(const char *restrict path,
						struct stat *restrict buff);


int32_t				sort_ascii_cmp(const void *a, const void *b);
int32_t				sort_ascii_dirents_cmp(const void *a, const void *b);
int32_t				sort_time_stats_cmp(const void *a, const void *b);

void				quick_sort(void *_base,
						const size_t _n_el,
						const size_t _width,
						int32_t (*_cmp)(const void*, const void*));

struct dirent		*dup_dirent(const struct dirent *restrict src);
struct stat			*dup_stat(const struct stat *restrict src);

void				*free_curr_dir(CurrDir **curr_dir);
void				*free_curr_in_dir_obj(InDirObject *obj);
void				*free_valid_args(char **args, const int32_t max);

#endif
