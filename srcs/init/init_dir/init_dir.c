/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 16:08:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static struct s_dir
	*s_precalc_in_dir_objs(struct s_dir_init *restrict h)
{
	struct s_dir	*out;
	struct dirent	*dirent;

	LS_ASSERT(out = ft_memalloc(sizeof(*out)));
	while ((dirent = readdir(h->dir)))
		out->n_objs += !(!GDI_FLAGS_IS_BIT(BIT_A_HIDDEN)
					&& '.' == dirent->d_name[0]);
	rewinddir(h->dir);
	if (!GDI_FLAGS_IS_BIT(BIT_A_HIDDEN) && !out->n_objs)
		LS_ASSERT(out->objs = ft_memalloc(sizeof(*out->objs)));
	else
		LS_ASSERT(out->objs = ft_memalloc(sizeof(*out->objs) * out->n_objs));
	return (out);
}

static struct s_dir
	*s_read_dir(struct s_dir_init *restrict h, const char *restrict path)
{
	GDI_MAXLEN_GET_VALUE() = 0UL;
	while ((h->d = readdir(h->dir)))
		if (!(!GDI_FLAGS_IS_BIT(BIT_A_HIDDEN) && '.' == h->d->d_name[0]))
		{
			if (!init_stat(u_full_path(h->tmp, path, h->d->d_name), &h->st))
				return (free_dir(&h->out));
			if (!(h->obj = init_dir_obj(&h->out->objs[++h->i],
							&h->st, h->d->d_name)))
				return (free_dir(&h->out));
		}
	return (h->out);
}

struct s_dir
	*init_dir(const char *path, const bool force_open_dir)
{
	struct s_dir_init	h;

	init_stat(path, &h.st);
	h.i = ~0U;
	if (!force_open_dir && !S_ISDIR(h.st.st_mode))
		return (init_file(path));
	LS_ASSERT_MGS(h.dir = opendir(path), path);
	h.out = s_precalc_in_dir_objs(&h);
	LS_ASSERT(h.tmp = ft_strnew(1023UL));
	h.out = s_read_dir(&h, path);
	ft_strdel(&h.tmp);
	closedir(h.dir);
	if (h.out && h.out->n_objs)
		return (h.out);
	return (free_dir(&h.out));
}
