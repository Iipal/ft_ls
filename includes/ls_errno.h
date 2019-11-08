/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 22:44:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_ERRNO_H
# define LS_ERRNO_H

# define ERR  "ft_ls: "
# define PERR "ft_ls"

# define E_ALLOC ERR "Where is your memory, pal?"

# define E_ALLOC_OBJ(obj) ERR "Can't allocate memory for \'" obj "\'."
# define OBJ_DIRENT "struct dirent duplicate"
# define OBJ_STAT   "struct stat duplicate"

#endif
