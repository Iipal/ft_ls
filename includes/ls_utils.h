/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 02:38:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 16:14:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_UTILS_H
# define LS_UTILS_H

# include <stddef.h>

char	*u_full_path(char *dst,
			const char *dir_path,
			const char *file);

#endif
