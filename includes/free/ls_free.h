/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:54:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 12:57:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FREE_H
# define LS_FREE_H

# include "ls_s_dir.h"

void
*free_dir(struct s_dir **curr_dir);

extern void
*free_dir_obj(struct s_object *obj);

#endif
