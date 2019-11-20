/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_win_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:58:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/21 01:09:33 by tmaluh           ###   ########.fr       */
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
		DEF_STRERR(ERR, "get_term_win_size");
		return (false);
	}
	g_win_size = (s2si) { w_size.ws_col, w_size.ws_row };
	return (true);
}
