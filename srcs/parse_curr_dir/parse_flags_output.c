#include "ls.h"

static bool	s_check_subdirs(char *prev_dir, uint32_t const n_objs,
								InDirObject const *const objs)
{
	char				*d_name;
	char				*subdir;
	uint32_t			i;

	i = ~0U;
	d_name = NULL;
	subdir = (char*)ft_memalloc(sizeof(char) * 256);
	while (n_objs > ++i)
	{
		d_name = objs[i].dirent->d_name;
		if (('.' == d_name[0] || ('.' == d_name[0] && '.' == d_name[1]))
		&& !S_ISDIR(objs[i].stat->st_mode))
			continue ;
		subdir = u_full_path(subdir, prev_dir, d_name);
		ft_printf("\n%s:\n", subdir);
		parse_dir(subdir);
	}
	ft_strdel(&subdir);
	return (true);
}

void	parse_flags_output(char *path, CurrDir *cd)
{
	if (g_sort_type != e_sort_none)
		g_sorts_fn[g_sort_type](cd->n_objs, cd->objs);
	if (g_print_format != e_print_line_by_line)
		g_prints_fn[g_print_format](cd->n_objs, cd->objs);
	if (IS_BIT(g_flags, BIT_R_RECURSIVE))
		s_check_subdirs(path, cd->n_objs, cd->objs);
}
