/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:37:39 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:54:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_TYPES_H
# define LS_TYPES_H

/*
** My own typedefs for compatibility between Linux and MacOS:
*/
typedef long long	t_blkcnt_t;
typedef long		t_time_t;

typedef struct	s_2si
{
	size_t	x;
	size_t	y;
}				t_s2si;

typedef struct	s_2sl
{
	long	x;
	long	y;
}				t_s2sl;

#endif
