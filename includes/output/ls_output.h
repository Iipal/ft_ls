/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:49:53 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/27 17:41:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_OUTPUT_H
# define LS_OUTPUT_H

# include "ls_df.h"
# include "ls_lf.h"

void
output(const char *restrict path, const struct s_dir *restrict cd);

#endif
