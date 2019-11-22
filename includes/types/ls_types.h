/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:37:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 12:48:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_TYPES_H
# define LS_TYPES_H

# ifdef __APPLE__
typedef blkcnt_t	t_blkcnt_t;
typedef time_t		t_time_t;
# else
typedef __blkcnt_t	t_blkcnt_t;
typedef __time_t	t_time_t;
# endif

typedef struct	s_2si
{
	int	x;
	int	y;
}				t_s2si;

typedef struct	s_2sl
{
	long	x;
	long	y;
}				t_s2sl;

#endif
