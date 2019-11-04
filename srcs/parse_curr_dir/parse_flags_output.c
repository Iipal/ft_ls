#include "ls.h"

static bool	s_check_subdirs(char *prev_dir, uint32_t const n_objs,
								InDirObject const *const objs)
{
	char		*d_name;
	char		*subdir;
	uint32_t	i;

	i = ~0U;
	d_name = NULL;
	subdir = (char*)ft_memalloc(sizeof(char) * 256);
	while (n_objs > ++i)
	{
		d_name = objs[i].dirent->d_name;
		if (('.' == d_name[0] && '\0' == d_name[1])
		|| ('.' == d_name[0] && '.' == d_name[1] && '\0' == d_name[2])
		|| !S_ISDIR(objs[i].stat->st_mode))
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
	if (!IS_BIT(g_flags, BIT_F_NOT_SORTED))
	{
		if (IS_BIT(g_flags, BIT_T_TIME))
			quick_sort(cd->objs, cd->n_objs, sizeof(InDirObject),
				sort_time_stats_cmp);
		else
			quick_sort(cd->objs, cd->n_objs, sizeof(InDirObject),
				sort_ascii_dirents_cmp);
	}
	if (IS_BIT(g_flags, BIT_L_LIST))
		plf_objs(cd->n_objs, cd->objs);
	else
		pdf_objs(cd->n_objs, cd->objs);
	if (IS_BIT(g_flags, BIT_R_RECURSIVE))
		s_check_subdirs(path, cd->n_objs, cd->objs);
}
