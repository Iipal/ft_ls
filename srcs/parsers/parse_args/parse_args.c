/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:11:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 19:46:39 by tmaluh           ###   ########.fr       */
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
	dst[g_va_counter++] = (struct s_arg) { ft_strndup(arg.path, arg.path_len),
											arg.path_len, arg.is_dir, { 0 } };
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
			out = s_dup_arg(out, (struct s_arg){av[i],
				ft_strlen(av[i]), S_ISDIR(st.st_mode)});
	choose_sort(out,
		g_va_counter,
		sizeof(struct s_arg),
		sort_isdir_args_cmp);
	choose_sort(out,
		g_va_notdir_counter,
		sizeof(struct s_arg),
		sort_ascii_args_cmp);
	choose_sort(out + g_va_notdir_counter,
		g_va_counter - g_va_notdir_counter,
		sizeof(struct s_arg),
		sort_ascii_args_cmp);
	return (out);
}

static inline void __attribute__((__always_inline__))
	s_parse_arg_dir(struct s_arg *arg, int ac, int i)
{
	g_src_path = ft_strndup(arg->path, arg->path_len);
	if (1 < ac)
		ft_printf("%s:\n", g_src_path);
	parse_dir(g_src_path);
	if (g_va_counter != i + 1)
		ft_putchar('\n');
}

static inline void  __attribute__((__always_inline__))
	s_parse_arg_file(const char *restrict path, int i)
{
	ft_putstr(path);
	if (g_va_notdir_counter > i + 1)
		ft_putchar(IS_BIT(g_flags, BIT_1_ONE) ? '\n' : ' ');
	else if (g_va_notdir_counter <= i + 1)
	{
		ft_putchar('\n');
		if (g_va_notdir_counter != g_va_counter)
			ft_putchar('\n');
	}
}

int
	parse_args(int ac, char **av)
{
	struct s_arg	*args;
	int32_t			i;

	if (!(args = s_pre_parse_errno_args(ac, av)))
		return (g_main_ret = EXIT_FAILURE);
	i = -1;
	while (g_va_counter > ++i)
	{
		ft_strdel(&g_src_path);
		if (args[i].is_dir)
			s_parse_arg_dir(&args[i], ac, i);
		else
			s_parse_arg_file(args[i].path, i);
		ft_strdel(&args[i].path);
	}
	free(args);
	return (EXIT_SUCCESS);
}
