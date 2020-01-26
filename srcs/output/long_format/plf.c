/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:52:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void
	plf_obj(char *restrict fmt_str,
		const char *restrict path,
		const struct s_object *restrict obj)
{
	static struct s_plf	plf_obj;

	plf_obj = (struct s_plf) {
		plf_get_permission((char[STR_LEN_PERMISSION]){ 0 }, obj->st->mode),
		plf_get_dev_info((char[STR_LEN_DEVICE]){ 0 }, obj->st),
		plf_get_date((char[STR_LEN_DATE]){ 0 }, obj->st),
		GDI_FLAGS_IS_BIT(BIT_G_NO_OWNER) ? "" : getpwuid(obj->st->uid)->pw_name,
		getgrgid(obj->st->gid)->gr_name
	};
	ft_fprintf(stdout, fmt_str, plf_obj.perm, obj->acl_ch, obj->st->nlink,
		plf_obj.pw_name, plf_obj.gr_name, plf_obj.dev_info, plf_obj.date, path);
	if (S_ISLNK(obj->st->mode))
		plf_get_link(obj->d_name);
	fwrite("\n", sizeof(char), 1UL, stdout);
}

void
	plf(const size_t n_objs, const struct s_object *restrict objs)
{
	char		*fmt_str;
	size_t		i;
	t_blkcnt_t	total;

	i = ~0UL;
	total = 0L;
	fmt_str = plf_get_fmt_str(n_objs, objs, &total);
	if (!GDI_FLAGS_IS_BIT(BIT_NO_TOTAL))
		ft_fprintf(stdout, "total %lld\n", total);
	while (n_objs > ++i)
		plf_obj(fmt_str, (objs[i].clr_name ? objs[i].clr_name : objs[i].d_name),
			&objs[i]);
}
