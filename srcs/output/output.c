/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:40:07 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/15 15:39:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline void	output(const struct s_dir *restrict cd)
{
	if (!GDI_FLAGS_IS_BIT(BIT_F_NO_SORT))
	{
		if (GDI_FLAGS_IS_BIT(BIT_T_SORT_TIME))
			choose_sort(cd->objs, cd->n_objs,
				sizeof(struct s_object), sort_time_objects_cmp);
		else if (GDI_FLAGS_IS_BIT(BIT_S_SORT_SIZE))
			choose_sort(cd->objs, cd->n_objs,
				sizeof(struct s_object), sort_size_objects_cmp);
		else
			choose_sort(cd->objs, cd->n_objs,
				sizeof(struct s_object), sort_ascii_objects_cmp);
	}
	if (GDI_FLAGS_IS_BIT(BIT_L_LIST))
		plf(cd->n_objs, cd->objs);
	else
		pdf(cd->n_objs, cd->objs);
}
