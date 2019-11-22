/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_dir.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:42:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 12:44:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_S_DIR_H
# define LS_S_DIR_H

# include <stdbool.h>

# include "ls_s_object.h"

struct	s_dir
{
	struct s_object	*objs;
	int32_t			n_objs;
	bool			is_file;
};

#endif
