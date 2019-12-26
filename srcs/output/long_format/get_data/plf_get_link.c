/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf_get_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:01:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/26 04:00:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	plf_get_link(const char *restrict file)
{
	char	*link_name;
	char	*full_path;

	link_name = (char[1024]){ 0 };
	full_path = (char[1024]){ 0 };
	readlink(u_full_path(full_path, g_src_path, file), link_name, 1024UL);
	ft_fprintf(stdout, " -> %s", link_name);
}
