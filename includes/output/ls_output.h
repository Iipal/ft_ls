/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:49:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/25 21:03:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_OUTPUT_H
# define LS_OUTPUT_H

# include "ls_df.h"
# include "ls_lf.h"

/*
**	Store the dupcliate of argument name which currently parsing.
**	 (Used for links)
*/
extern char		g_src_path[1024];

/*
** Store the max item name lenght in directory which currently parsing.
**	 (Used for corrent output formating)
*/
extern size_t	g_max_name_len;

void
output(const char *restrict path, const struct s_dir *restrict cd);

#endif
