/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_df.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:49:55 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:53:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_DF_H
# define LS_DF_H

# include "ls_s_object.h"

/*
** PDF - Print Default Format
*/
extern void	pdf(const size_t n_objs, const struct s_object *const objs);

#endif
