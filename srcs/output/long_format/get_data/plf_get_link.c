/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:01:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 14:46:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	plf_get_link(const char *restrict file)
{
	char	link_name[1024];
	char	full_path[1024];

	ft_bzero(link_name, sizeof(char) * 1024);
	ft_bzero(full_path, sizeof(char) * 1024);
	readlink(u_full_path(full_path, g_src_path, file), link_name, 1024UL);
	ft_printf(" -> %s", link_name);
}
