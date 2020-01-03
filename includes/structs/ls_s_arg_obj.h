/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_arg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:47:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:01:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_S_ARG_OBJ_H
# define LS_S_ARG_OBJ_H

# include <stdbool.h>

struct	s_arg_obj
{
	char	*path;
	bool	is_dir;
	char	_dummy[7] __attribute__((unused));
};

#endif
