/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:40:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 20:29:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include "ls_errno.h"
# include "ls_flags.h"

# include <dirent.h>

struct	s_environment
{
	Flags	flags;
};

# define ENVIRONMENT typedef struct s_environment Environment

ENVIRONMENT;

bool	ls(size_t ac, strtab av);

bool	ls_parse_flags(string flags, Environment *const env);

void	ls_free(Environment **env);

#endif
