/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 12:09:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static struct s_dir
	*s_precalc_in_dir_objs(struct s_dir_init *restrict h,
		const char *restrict path)
{
	struct s_dir	*out;
	struct dirent	*dirent;

	if (!h->dir)
		return (ls_errno_msg(__FILE__, PFUNC, __LINE__, path));
	if (!(out = ft_memalloc(sizeof(struct s_dir))))
		return (ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc"));
	while ((dirent = readdir(h->dir)))
		out->n_objs += !(!IS_BIT(g_flags, BIT_A_HIDDEN)
					&& '.' == dirent->d_name[0]);
	rewinddir(h->dir);
	if (!IS_BIT(g_flags, BIT_A_HIDDEN) && !out->n_objs)
	{
		if (!(out->objs = ft_memalloc(sizeof(struct s_object) * 1UL)))
			return (ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc"));
	}
	else if (!(out->objs = ft_memalloc(sizeof(struct s_object) * out->n_objs)))
		return (ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_memalloc"));
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
	h.dir = opendir(path);
	if (!(h.out = s_precalc_in_dir_objs(&h, path)))
		return (NULL);
	if (!(h.tmp = ft_strnew(1024UL)))
		return (ls_errno_msg(__FILE__, PFUNC, __LINE__, "ft_strnew"));
	h.out = s_read_dir(&h, path);
	ft_strdel(&h.tmp);
	closedir(h.dir);
	return (h.out->n_objs ? h.out : free_dir(&h.out));
}
