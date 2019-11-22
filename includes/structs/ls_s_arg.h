/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_arg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:47:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 12:47:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_S_ARG_H
# define LS_S_ARG_H

# include <sys/types.h>
# include <stdbool.h>

struct	s_arg
{
	char	*path;
	size_t	path_len;
	bool	is_dir;
	char	dummy[7];
};

#endif
