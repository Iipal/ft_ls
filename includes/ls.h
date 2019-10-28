/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 22:16:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include "ft_printf.h"
# include "ls_errno.h"
# include "ls_flags.h"
# include "ls_structs.h"

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

void			pre_parse_errno(char *path);

bool			parse_dir(char *path);
void			parse_file(char *path, InDirObject const *const obj);

void			parse_flags_output(char *path, CurrDir *cd);

/*
** PLF - Print Long Format
*/
void			plf_objs(size_t const n_objs, InDirObject const *const objs);
void			plf_obj(char const *const path, InDirObject const *const objs);

char			*plf_get_date(char *date_str, t_time_t const date_time);
char			*plf_get_permission(char *perm_str, mode_t const st_mode_perm);

void			print_default_format(size_t const n_objs,
					InDirObject const *const objs);

CurrDir			*init_only_file(char *const path);
CurrDir			*init_curr_dir(char *const path, bool const force_open_dir);
InDirObject		*init_curr_in_dir_obj(InDirObject *dst,
					struct stat *stat, struct dirent *dirent);
bool			init_lstat_check(char *const path, struct stat *buff);
bool			init_lstat_check_no_errno(char *const path, struct stat *buff);

char			**sort_ascii_tab_str(size_t const n, char **tab);
void			sort_ascii_dirents(size_t const objs_counter,
					InDirObject *const objs);
void			sort_time_stats(size_t const objs_counter,
					InDirObject *const objs);

struct dirent	*dup_dirent(struct dirent const *const src);
struct stat		*dup_stat(struct stat const *const src);

bool			parse_flags(char const *flags_str);

void			*free_curr_dir(CurrDir **curr_dir);
void			*free_curr_in_dir_obj(InDirObject *obj);
void			*free_valid_args(char **args, int max);

#endif
