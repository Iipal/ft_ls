/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:30:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:12:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static struct s_dir
	*s_precalc_in_dir_objs(DIR *restrict dir)
{
	struct s_dir	*out;
	struct dirent		*dirent;

	if (!dir)
		return (ls_errno_msg(__FILE__, __func__));
	if (!(out = ft_memalloc(sizeof(struct s_dir))))
		return (ls_errno_msg(__FILE__, __func__));
	while ((dirent = readdir(dir)))
		out->n_objs += !(!IS_BIT(g_flags, BIT_A_HIDDEN)
					&& '.' == dirent->d_name[0]);
	rewinddir(dir);
	if (!IS_BIT(g_flags, BIT_A_HIDDEN) && !out->n_objs)
	{
		if (!(out->objs = ft_memalloc(sizeof(struct s_object) * 1UL)))
			return (ls_errno_msg(__FILE__, __func__));
	}
	else if (!(out->objs = ft_memalloc(sizeof(struct s_object)
										* out->n_objs)))
			return (ls_errno_msg(__FILE__, __func__));
	return (out);
}

struct s_dir
	*init_dir(const char *path, const bool force_open_dir)
{
	struct s_dir		*out;
	struct s_dir_init	h;
	uint32_t			i;

	if (!(i = ~0U) || !init_stat_no_err(path, &h.st))
		return (NULL);
	if (!force_open_dir && !S_ISDIR(h.st.st_mode))
		return (init_file(path));
	if (!(h.dir = opendir(path)) || !(h.tmp = ft_strnew(255UL)))
		return (ls_errno_msg(__FILE__, __func__));
	if (!(out = s_precalc_in_dir_objs(h.dir)))
		return (NULL);
	while ((h.d = readdir(h.dir)))
		if (!(!IS_BIT(g_flags, BIT_A_HIDDEN) && '.' == h.d->d_name[0]))
		{
			if (!init_stat(u_full_path(h.tmp, path, h.d->d_name), &h.st))
				return ((struct s_dir*)(*(ptrdiff_t*)free_dir(&out)
						+ *(ptrdiff_t*)ls_errno_msg(__FILE__, __func__)));
			if (!(h.obj = init_dir_obj(&out->objs[++i],
							&h.st, h.d, h.d->d_name)))
				return (free_dir(&out));
		}
	closedir(h.dir);
	ft_strdel(&h.tmp);
	return (out->n_objs ? out : free_dir(&out));
}
