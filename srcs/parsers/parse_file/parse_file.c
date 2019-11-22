/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:30:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 10:51:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_long_format_listing.h"

static inline bool __attribute__((__always_inline__))
	s_check_def_or_under_link_print(const char *restrict file,
		const struct s_object *restrict obj)
{
	bool	print_as_dir;

	print_as_dir = false;
	if (S_ISLNK(obj->stat->st_mode))
		print_as_dir = true;
	else
		ft_putendl(file);
	return (print_as_dir);
}

static inline bool __attribute__((__always_inline__))
	s_check_plf_or_under_link_print(const char *restrict file,
		const struct s_object *restrict obj)
{
	bool		print_as_dir;
	t_blkcnt_t	t;

	print_as_dir = false;
	if (S_ISLNK(obj->stat->st_mode) && ft_strchr(file, '/'))
		print_as_dir = true;
	else
		plf_obj(plf_fmt_str(plf_width_spec(1UL, obj, &t)), file, obj, true);
	return (print_as_dir);
}

inline void
	parse_file(const char *restrict file,
		const struct s_object *restrict obj)
{
	struct s_dir	*cd;
	bool				is_link_parse_as_dir;

	cd = NULL;
	is_link_parse_as_dir = false;
	if (!IS_BIT(g_flags, BIT_L_LIST))
		is_link_parse_as_dir = s_check_def_or_under_link_print(file, obj);
	else
		is_link_parse_as_dir = s_check_plf_or_under_link_print(file, obj);
	if (is_link_parse_as_dir)
	{
		cd = init_dir(file, true);
		output(file, cd);
		free_dir(&cd);
	}
}
