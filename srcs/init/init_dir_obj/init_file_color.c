/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:33:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/26 00:23:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline char
	*s_select_color(const mode_t mode, size_t *restrict clr_len)
{
	char	*out;

	out = NULL;
	if (S_ISDIR(mode))
		out = LS_CLR_DIR;
	else if (S_ISCHR(mode))
		out = LS_CLR_CHR;
	else if (S_ISBLK(mode))
		out = LS_CLR_BLK;
	else if (S_ISLNK(mode))
		out = LS_CLR_LNK;
	else if (mode & S_IXUSR || mode & S_IXGRP || mode & S_IXOTH)
		out = LS_CLR_EXE;
	else if (S_ISSOCK(mode))
		out = LS_CLR_SOCK;
	if (out)
	{
		*clr_len = ft_strlen(out);
		out = ft_strndup(out, *clr_len);
	}
	return (out);
}

char
	*init_file_color(const char *restrict filename,
		const size_t filename_len,
		const mode_t mode,
		size_t *restrict clr_len)
{
	char		*out;
	char		*clr;
	size_t		out_len;
	size_t		clr_end_len;

	out = NULL;
	*clr_len = 0UL;
	clr_end_len = sizeof(LS_CLR_DEFAULT) - 1UL;
	if ((clr = s_select_color(mode, clr_len)))
	{
		out_len = *clr_len + filename_len + clr_end_len;
		out = ft_strnew(out_len);
		out = ft_strncpy(out, clr, *clr_len);
		ft_strncpy(out + *clr_len, filename, filename_len);
		ft_strcpy(out + filename_len + *clr_len, LS_CLR_DEFAULT);
		ft_strdel(&clr);
		*clr_len = out_len;
	}
	return (out);
}
