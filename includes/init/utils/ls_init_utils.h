/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:56:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 12:57:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_INIT_UTILS_H
# define LS_INIT_UTILS_H

# include <dirent.h>
# include <sys/stat.h>

extern struct dirent
*dup_dirent(const struct dirent *restrict src);

extern struct stat
*dup_stat(const struct stat *restrict src);

#endif
