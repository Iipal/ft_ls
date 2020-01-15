/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:01:53 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:20:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	plf_get_link(const char *restrict file)
{
	char	*link_name;
	char	*full_path;

	link_name = (char[GDI_DBUF_SIZE]){ 0 };
	full_path = (char[GDI_DBUF_SIZE]){ 0 };
	readlink(u_full_path(full_path, GDI_SRC_GET_VALUE(), file),
		link_name, GDI_SRC_SIZE);
	ft_fprintf(stdout, " -> %s", link_name);
}
