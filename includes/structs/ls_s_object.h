/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:44:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 12:56:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_S_OBJECT_H
# define LS_S_OBJECT_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>

struct	s_object
{
	struct dirent	*dirent;
	struct stat		*stat;
	size_t			d_name_len;
	char			acl_ch;
};

#endif
