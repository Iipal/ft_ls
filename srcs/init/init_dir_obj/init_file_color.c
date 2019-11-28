/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:33:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/28 17:31:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline char
	*s_select_color(const struct stat *restrict st, size_t *restrict clr_len)
{
	char	*out;

	out = NULL;
	if (S_ISDIR(st->st_mode))
	{
		out = PF_FG_CLR_LCYAN;
		*clr_len += sizeof(PF_FG_CLR_LCYAN) - 1UL;
	}
	else if (S_ISLNK(st->st_mode))
	{
		out = PF_FG_CLR_MAGENTA;
		*clr_len += sizeof(PF_FG_CLR_MAGENTA) - 1UL;
	}
	else if (IS_BIT(st->st_mode, S_IXUSR))
	{
		out = PF_FG_CLR_RED;
		*clr_len += sizeof(PF_FG_CLR_RED) - 1UL;
	}
	return (out);
}

inline char
	*init_file_color(const char *restrict filename,
		const size_t filename_len,
		const struct stat *restrict st,
		size_t *restrict clr_len)
{
	char	*out;
	char	*clr;
	size_t	out_len;

	out = NULL;
	*clr_len = 0UL;
	if (!g_isatty_ret || !IS_BIT(g_flags, BIT_G_COLOR))
		return (out);
	clr = s_select_color(st, clr_len);
	out_len = filename_len + sizeof(PF_BG_CLR_DEFAULT);
	if (clr)
	{
		out = ft_strnew(out_len + *clr_len);
		out = ft_strncpy(out, clr, *clr_len);
		ft_strcpy(out + *clr_len, filename);
		ft_strcpy(out + ft_strlen(out), PF_FG_CLR_DEFAULT);
		*clr_len += out_len;
	}
	return (out);
}
