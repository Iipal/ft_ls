/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_stat.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:44:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:53:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_S_STAT_H
# define LS_S_STAT_H

# include <sys/stat.h>

# include "ls_types.h"

struct	s_stat
{
	uid_t		uid;
	gid_t		gid;
	t_time_t	a_time;
	t_time_t	c_time;
	t_time_t	m_time;
	off_t		size;
	t_blkcnt_t	blocks;
	dev_t		rdev;
	mode_t		mode;
	nlink_t		nlink;
};

#endif
