/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:40:07 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/29 18:50:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	output(const char *restrict path, const struct s_dir *restrict cd)
{
	if (!IS_BIT(g_flags, BIT_F_NO_SORT))
	{
		if (IS_BIT(g_flags, BIT_T_SORT_TIME))
			choose_sort(cd->objs, cd->n_objs,
				sizeof(struct s_object), sort_time_objects_cmp);
		else if (IS_BIT(g_flags, BIT_S_SORT_SIZE))
			choose_sort(cd->objs, cd->n_objs,
				sizeof(struct s_object), sort_size_objects_cmp);
		else
			choose_sort(cd->objs, cd->n_objs,
				sizeof(struct s_object), sort_ascii_objects_cmp);
	}
	if (IS_BIT(g_flags, BIT_L_LIST))
		plf(cd->n_objs, cd->objs);
	else
		pdf(cd->n_objs, cd->objs);
}
