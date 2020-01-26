/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdi_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:21:19 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/25 23:35:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

inline int32_t	*gdi_flags_get_ptr(void)
{
	static int32_t	flags;

	return (&flags);
}

inline void		gdif_internal_checks(const int32_t mask)
{
	GDI_FLAGS_SET_BIT(mask);
	if (GDI_FLAGS_IS_BIT(BIT_G_NO_OWNER))
		GDI_FLAGS_SET_BIT(BIT_L_LIST);
	else if (GDI_FLAGS_IS_BIT(BIT_L_LIST))
		GDI_FLAGS_UNSET_BIT(BIT_1_ONE);
	else if (GDI_FLAGS_IS_BIT(BIT_1_ONE))
		GDI_FLAGS_UNSET_BIT(BIT_L_LIST);
	else if (GDI_FLAGS_IS_BIT(BIT_F_NO_SORT))
		GDI_FLAGS_SET_BIT(BIT_A_HIDDEN);
}

inline void		gdi_flags_parser(struct s_arg_av *restrict a)
{
	const char	valid_flags[16] = { F_ONE, F_HIDDEN, F_NO_SORT,
		F_COLOR, F_NO_OWNER, F_LIST, F_RECURSIVE, F_REVERSE, F_SORT_SIZE,
		F_FULL_TIME, F_SORT_TIME, F_ACCESS };
	size_t		flag_i;
	bool		stop;

	flag_i = 0UL;
	stop = false;
	while (!stop && a->ac && '-' == **a->av)
	{
		while (!stop && *++*a->av)
			if ('-' == **a->av)
				stop = true;
			else if (F_MAX_QTY - 1
			> (flag_i = ft_strchr(valid_flags, **a->av) - valid_flags))
				gdif_internal_checks(TO_N_BIT(flag_i));
			else
				errx(EXIT_FAILURE,
					"illegal option -- %c\n%s", **a->av, FLAGS_USAGE);
		*a = (struct s_arg_av) { a->av + 1, a->ac - 1 };
	}
}
