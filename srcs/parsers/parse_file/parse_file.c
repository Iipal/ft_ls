/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:30:05 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 15:40:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline bool __attribute__((__always_inline__))
	s_check_def_or_under_link_print(const char *restrict file,
		const struct s_object *restrict obj, const bool is_endl)
{
	bool	is_print_as_dir;

	is_print_as_dir = false;
	if (S_ISLNK(obj->st->mode) && file[ft_strlen(file) - 1] == '/')
		is_print_as_dir = true;
	else
		is_endl ? ft_putendl(file) : ft_putstr(file);
	return (is_print_as_dir);
}

static inline bool __attribute__((__always_inline__))
	s_check_plf_or_under_link_print(const char *restrict file,
		const struct s_object *restrict obj)
{
	bool		is_print_as_dir;
	t_blkcnt_t	t;

	is_print_as_dir = false;
	if (S_ISLNK(obj->st->mode) && file[ft_strlen(file) - 1] == '/')
		is_print_as_dir = true;
	else
		plf_obj(plf_get_fmt_str(1UL, obj, &t), file, obj);
	return (is_print_as_dir);
}

void
	parse_file(const char *restrict file,
		const struct s_object *restrict obj,
		const bool is_endl)
{
	struct s_dir	*cd;
	bool			is_print_as_dir;

	cd = NULL;
	is_print_as_dir = false;
	if (!GDI_FLAGS_IS_BIT(BIT_L_LIST))
		is_print_as_dir = s_check_def_or_under_link_print(file, obj, is_endl);
	else
		is_print_as_dir = s_check_plf_or_under_link_print(file, obj);
	if (is_print_as_dir)
	{
		cd = init_dir(file, true);
		output(cd);
		free_dir(&cd);
	}
}
