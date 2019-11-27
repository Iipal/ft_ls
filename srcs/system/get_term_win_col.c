/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_win_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:58:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/27 19:05:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline int	get_term_win_col(void)
{
	struct winsize	w_size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w_size);
	return (w_size.ws_col);
}
