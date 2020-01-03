/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:49:53 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/03 20:21:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_OUTPUT_H
# define LS_OUTPUT_H

# include "ls_df.h"
# include "ls_lf.h"

# include "ls_output_colors.h"

extern void
output(const struct s_dir *restrict cd);

#endif
