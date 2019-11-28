/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:11:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 14:01:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int32_t	g_va_counter = 0;
static int32_t	g_va_notdir_counter = 0;

static inline struct s_arg __attribute__((__always_inline__))
	*s_dup_arg(struct s_arg *restrict dst, const struct s_arg arg)
{
	if (!arg.is_dir)
		++g_va_notdir_counter;
	if (!dst)
		dst = ft_memalloc(sizeof(struct s_arg));
	else
		dst = ft_memrealloc(dst, sizeof(struct s_arg) * g_va_counter,
								sizeof(struct s_arg) * (g_va_counter + 1));
	dst[g_va_counter++] = (struct s_arg) { ft_strdup(arg.path), arg.is_dir };
	return (dst);
}

static struct s_arg
	*s_pre_parse_errno_args(int32_t ac, char **av)
{
	struct s_arg	*out;
	struct stat		st;
	int32_t			i;

	i = -1;
	out = NULL;
	while (ac > ++i)
		if (init_stat(av[i], &st))
			out = s_dup_arg(out, (struct s_arg){ av[i], S_ISDIR(st.st_mode) });
	choose_sort(out, g_va_counter, sizeof(struct s_arg), sort_isdir_args_cmp);
	choose_sort(out, g_va_notdir_counter,
		sizeof(struct s_arg), sort_ascii_args_cmp);
	choose_sort(out + g_va_notdir_counter, g_va_counter - g_va_notdir_counter,
		sizeof(struct s_arg), sort_ascii_args_cmp);
	return (out);
}

int
	parse_args(int ac, char **av)
{
	struct s_arg	*args;
	int32_t			i;

	if (!(args = s_pre_parse_errno_args(ac, av)))
		return (g_main_ret = EXIT_FAILURE);
	if (g_va_notdir_counter)
	{
		parse_args_files_as_dir(args, g_va_notdir_counter);
		(g_va_counter - g_va_notdir_counter) ? ft_putchar('\n') : 0;
	}
	i = -1;
	while (g_va_counter > ++i)
	{
		if (args[i].is_dir)
		{
			if (1 < ac)
				ft_printf("%s:\n", args[i].path);
			parse_dir(args[i].path);
			if (g_va_counter != i + 1)
				ft_putchar('\n');
		}
		ft_strdel(&args[i].path);
	}
	free(args);
	return (EXIT_SUCCESS);
}
