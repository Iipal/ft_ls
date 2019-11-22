/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_dir_init.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:45:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 12:47:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_S_DIR_INIT_H
# define LS_S_DIR_INIT_H

# include "ls_s_object.h"

struct	s_dir_init
{
	DIR				*dir;
	struct s_object	*obj;
	struct dirent	*d;
	struct stat		st;
	char			*tmp;
};

#endif
