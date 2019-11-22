/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_win_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:58:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 00:53:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline bool	get_term_win_size(void)
{
	struct winsize	w_size;

	if (0 > ioctl(STDOUT_FILENO, TIOCGWINSZ, &w_size))
	{
		if (!isatty(fileno(stdout)))
			return (true);
		return ((bool)ls_errno_msg(__FILE__, __func__));
	}
	g_win_size = (t_s2si) { w_size.ws_col, w_size.ws_row };
	return (true);
}
