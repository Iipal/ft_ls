/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_full_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:35:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 18:59:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*u_full_path(char *restrict dst,
			const char *restrict dir_path,
			const char *restrict file)
{
	register size_t	dir_path_len = ft_strlen(dir_path);

	ft_strncpy(dst, dir_path, dir_path_len);
	if (dst[dir_path_len - 1] != '/')
		dst[dir_path_len++] = '/';
	ft_strcpy(dst + dir_path_len, file);
	dst[dir_path_len + ft_strlen(file)] = '\0';
	return (dst);
}
