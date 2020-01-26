/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:32:47 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/26 22:57:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static inline __attribute__((__always_inline__)) t_s2si
	s_get_term_size(const size_t n)
{
	float	x;

	x = (float)get_term_win_col() / (float)GDI_MAXLEN_GET_VALUE();
	if (1.0f > x)
		x = 1.0f;
	return ((t_s2si) { x, (float)n / x + 1.0f });
}

static inline __attribute__((__always_inline__)) void
	s_put_sep(size_t d_name_len, const size_t n, t_s2si xy)
{
	fwrite(GDI_FLAGS_IS_BIT(BIT_1_ONE) ? "\n" : " ", sizeof(char), 1UL, stdout);
	if (!GDI_FLAGS_IS_BIT(BIT_1_ONE) && xy.x + 1 < n / (float)xy.y)
		ft_printf("%s", ft_memset((char[1024]) { 0 }, ' ',
			GDI_MAXLEN_GET_VALUE() - d_name_len));
}

static inline __attribute__((__always_inline__)) struct s_pdf
	s_select_output_data(const struct s_object *restrict obj)
{
	return ((struct s_pdf) { obj->clr_name ? obj->clr_name : obj->d_name,
							obj->clr_name ? obj->clr_len : obj->d_name_len });
}

void
	pdf(const size_t n, const struct s_object *restrict objs)
{
	t_s2si			i;
	t_s2si			fmt;
	size_t			j;
	struct s_pdf	p;

	i.y = ~0UL;
	fmt = GDI_FLAGS_IS_BIT(BIT_1_ONE)
		? (t_s2si){ INT32_MAX, 1 } : s_get_term_size(n);
	while (fmt.y > ++i.y && (i.x = ~0UL))
	{
		while (fmt.x > ++i.x)
		{
			if (n <= (j = i.x * fmt.y + i.y))
				break ;
			p = s_select_output_data(&objs[j]);
			fwrite(p.name, sizeof(char), p.name_len, stdout);
			if (n - 1 > j)
				s_put_sep(objs[j].d_name_len, n, (t_s2si){i.x, fmt.y});
		}
		if (!GDI_FLAGS_IS_BIT(BIT_1_ONE))
			fwrite("\n", sizeof(char), 1UL, stdout);
	}
	if (GDI_FLAGS_IS_BIT(BIT_1_ONE))
		fwrite("\n", sizeof(char), 1UL, stdout);
}
