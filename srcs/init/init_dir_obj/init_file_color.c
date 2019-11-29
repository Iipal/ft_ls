/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:33:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 16:17:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline char
	*s_select_color(const mode_t mode, size_t *restrict clr_len)
{
	char	*out;

	out = NULL;
	if (S_ISDIR(mode))
		out = PF_FG_CLR_LCYAN;
	else if (S_ISCHR(mode))
		out = PF_BG_CLR_YELLOW PF_FG_CLR_BLACK;
	else if (S_ISBLK(mode))
		out = PF_BG_CLR_CYAN PF_FG_CLR_BLACK;
	else if (S_ISLNK(mode))
		out = PF_FG_CLR_MAGENTA;
	else if (mode & S_IXUSR || mode & S_IXGRP || mode & S_IXOTH)
		out = PF_FG_CLR_RED;
	else if (S_ISSOCK(mode))
		out = PF_FG_CLR_GREEN;
	if (out)
	{
		*clr_len = ft_strlen(out);
		out = ft_strndup(out, *clr_len);
	}
	return (out);
}

inline char
	*init_file_color(const char *restrict filename,
		const size_t filename_len,
		const mode_t mode,
		size_t *restrict clr_len)
{
	char			*out;
	char			*clr;
	size_t			out_len;
	const char		*clr_end = PF_FG_CLR_DEFAULT PF_BG_CLR_DEFAULT;
	const size_t	clr_end_len = sizeof(PF_FG_CLR_DEFAULT)
								+ sizeof(PF_BG_CLR_DEFAULT) - 2UL;

	out = NULL;
	*clr_len = 0UL;
	if (!g_isatty_ret || !IS_BIT(g_flags, BIT_G_COLOR))
		return (NULL);
	if ((clr = s_select_color(mode, clr_len)))
	{
		out_len = *clr_len + filename_len + clr_end_len;
		out = ft_strnew(out_len);
		out = ft_strncpy(out, clr, *clr_len);
		ft_strncpy(out + *clr_len, filename, filename_len);
		ft_strcpy(out + filename_len + *clr_len, clr_end);
		ft_strdel(&clr);
		*clr_len = out_len;
	}
	return (out);
}
