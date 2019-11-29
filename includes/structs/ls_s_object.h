/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:44:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:46:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_S_OBJECT_H
# define LS_S_OBJECT_H

# include <sys/types.h>

# include "ls_s_stat.h"

struct	s_object
{
	struct s_stat	*st;
	char			*d_name;
	char			*clr_name;
	size_t			d_name_len;
	size_t			clr_len;
	char			acl_ch;
	char			chunks[7];
};

#endif
