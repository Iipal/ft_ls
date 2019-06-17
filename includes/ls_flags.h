/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:10:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 20:05:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FLAGS_H
# define LS_FLAGS_H

# include "libft.h"
# include "ls_errno.h"

struct	s_flags
{
	bool	f_l_list_output;
	bool	f_r_recursive_output;
	bool	f_a_show_hidden;
	bool	f_r_reverse_sort;
	bool	f_t_time_sort;
};

# define FLAGS typedef struct s_flags Flags

FLAGS;

# define MAX_FLAGS 5

# define F_LIST_CHAR      'l'
# define F_RECURSIVE_CHAR 'R'
# define F_HIDDEN_CHAR    'a'
# define F_REVERSE_CHAR   'r'
# define F_TIME_CHAR      't'

# define E_INVALID_FLAG ERR "Invalid flag detected."

#endif
