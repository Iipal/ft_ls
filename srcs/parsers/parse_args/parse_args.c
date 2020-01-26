/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:11:08 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:51:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static size_t	g_va_counter = 0;
static size_t	g_va_notdir_counter = 0;

static inline struct s_arg_obj __attribute__((__always_inline__))
	*s_dup_arg(struct s_arg_obj *restrict dst, const struct s_arg_obj arg)
{
	if (!arg.is_dir)
		++g_va_notdir_counter;
	if (!dst)
		LS_ASSERT(dst = ft_memalloc(sizeof(struct s_arg_obj)));
	else
		LS_ASSERT(dst = ft_memrealloc(dst,
			sizeof(struct s_arg_obj) * g_va_counter,
			sizeof(struct s_arg_obj) * (g_va_counter + 1)));
	LS_ASSERT(dst[g_va_counter].path = ft_strdup(arg.path));
	dst[g_va_counter++].is_dir = arg.is_dir;
	return (dst);
}

static struct s_arg_obj
	*s_pre_parse_errno_args(struct s_arg_av *restrict const a)
{
	struct s_arg_obj	*out;
	struct stat			st;
	size_t				i;

	i = ~0UL;
	out = NULL;
	while (a->ac > ++i)
		if (init_stat(a->av[i], &st))
			out = s_dup_arg(out, (struct s_arg_obj){ a->av[i],
								S_ISDIR(st.st_mode), { 0 } });
	choose_sort(out, g_va_counter,
		sizeof(struct s_arg_obj), sort_isdir_args_cmp);
	choose_sort(out, g_va_notdir_counter,
		sizeof(struct s_arg_obj), sort_ascii_args_cmp);
	choose_sort(out + g_va_notdir_counter, g_va_counter - g_va_notdir_counter,
		sizeof(struct s_arg_obj), sort_ascii_args_cmp);
	return (out);
}

int
	parse_args(struct s_arg_av *restrict const a)
{
	struct s_arg_obj	*args;
	size_t				i;

	if (!(args = s_pre_parse_errno_args(a)))
		return (EXIT_FAILURE);
	if (g_va_notdir_counter)
	{
		parse_args_files_as_dir(args, g_va_notdir_counter);
		if (g_va_counter - g_va_notdir_counter)
			fwrite("\n", sizeof(char), 1UL, stdout);
	}
	i = -1;
	while (g_va_counter > ++i)
	{
		if (args[i].is_dir)
		{
			if (1 < a->ac)
				ft_fprintf(stdout, "%s:\n", args[i].path);
			parse_dir(args[i].path);
			if (g_va_counter != i + 1)
				fwrite("\n", sizeof(char), 1UL, stdout);
		}
		ft_strdel(&args[i].path);
	}
	free(args);
	return (EXIT_SUCCESS);
}
