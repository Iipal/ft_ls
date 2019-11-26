/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/26 13:39:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static struct s_dir
	*s_precalc_in_dir_objs(DIR *restrict dir, const char *restrict path)
{
	struct s_dir	*out;
	struct dirent	*dirent;

	if (!dir)
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, path));
	if (!(out = ft_memalloc(sizeof(struct s_dir))))
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "malloc"));
	while ((dirent = readdir(dir)))
		out->n_objs += !(!IS_BIT(g_flags, BIT_A_HIDDEN)
					&& '.' == dirent->d_name[0]);
	rewinddir(dir);
	if (!IS_BIT(g_flags, BIT_A_HIDDEN) && !out->n_objs)
	{
		if (!(out->objs = ft_memalloc(sizeof(struct s_object) * 1UL)))
			return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "malloc"));
	}
	else if (!(out->objs = ft_memalloc(sizeof(struct s_object) * out->n_objs)))
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "malloc"));
	return (out);
}

static struct s_dir
	*s_read_dir(struct s_dir_init *restrict h, const char *restrict path)
{
	while ((h->d = readdir(h->dir)))
		if (!(!IS_BIT(g_flags, BIT_A_HIDDEN) && '.' == h->d->d_name[0]))
		{
			if (!init_stat(u_full_path(h->tmp, path, h->d->d_name), &h->st))
				return (free_dir(&h->out));
			if (!(h->obj = init_dir_obj(&h->out->objs[++h->i],
							&h->st, h->d, h->d->d_name)))
				return (free_dir(&h->out));
		}
	closedir(h->dir);
	ft_strdel(&h->tmp);
	return (h->out);
}

inline struct s_dir
	*init_dir(const char *path, const bool force_open_dir)
{
	struct s_dir_init	h;

	g_max_name_len = 0UL;
	if (!(h.i = ~0U) || !init_stat(path, &h.st))
		return (NULL);
	if (!force_open_dir && !S_ISDIR(h.st.st_mode))
		return (init_file(path));
	if (!(h.tmp = ft_strnew(255UL)))
		return (ls_errno_msg(__FILE__, __PFUNC__, __LINE__, "ft_strnew"));
	h.dir = opendir(path);
	if (!(h.out = s_precalc_in_dir_objs(h.dir, path)))
		return (NULL);
	if (!s_read_dir(&h, path))
		return (NULL);
	return (h.out->n_objs ? h.out : free_dir(&h.out));
}
