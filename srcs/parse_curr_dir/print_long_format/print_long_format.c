/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 22:03:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 20:11:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "ls_long_format_listing.h"

static char	*s_get_permission(char *perm_str, mode_t const st_mode_perm)
{
	perm_str[0] = '-';
	if (S_ISDIR(st_mode_perm))
		perm_str[0] = 'd';
	else if (S_ISLNK(st_mode_perm))
		perm_str[0] = 'l';
	perm_str[1] = (st_mode_perm & S_IRUSR) ? 'r' : '-';
	perm_str[2] = (st_mode_perm & S_IWUSR) ? 'w' : '-';
	perm_str[3] = (st_mode_perm & S_IXUSR) ? 'x' : '-';
	perm_str[4] = (st_mode_perm & S_IRGRP) ? 'r' : '-';
	perm_str[5] = (st_mode_perm & S_IWGRP) ? 'w' : '-';
	perm_str[6] = (st_mode_perm & S_IXGRP) ? 'x' : '-';
	perm_str[7] = (st_mode_perm & S_IROTH) ? 'r' : '-';
	perm_str[8] = (st_mode_perm & S_IWOTH) ? 'w' : '-';
	perm_str[9] = (st_mode_perm & S_IXOTH) ? 'x' : '-';
	return (perm_str);
}

static char	*s_append_int_to_str(char *dst, int src)
{
	char	*tmp;

	tmp = ft_itoa(src);
	ft_strcpy(dst + ft_strlen(dst), tmp);
	ft_strdel(&tmp);
	return (dst);
}

static char	*s_get_date(char *date_str, t_time_t const date_time)
{
	static struct tm			*tm;
	static char const *const	date_months[] = { "Jan ", "Feb ", "Mar ",
	"Apr ", "May ", "Jun ", "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec " };

	tm = localtime(&date_time);
	ft_memset(date_str, 0, sizeof(char) * STR_LEN_DATE);
	date_str = ft_strcpy(date_str, date_months[tm->tm_mon]);
	date_str[4] = (10 > tm->tm_mday) ? ' ' : '\0';
	date_str = s_append_int_to_str(date_str, tm->tm_mday);
	date_str[ft_strlen(date_str)] = ' ';
	date_str[ft_strlen(date_str)] = (10 > tm->tm_hour) ? '0' : '\0';
	date_str = s_append_int_to_str(date_str, tm->tm_hour);
	date_str[ft_strlen(date_str)] = ':';
	date_str[ft_strlen(date_str)] = (10 > tm->tm_min) ? '0' : '\0';
	date_str = s_append_int_to_str(date_str, tm->tm_min);
	return (date_str);
}

static void	s_print_link(char const *const path)
{
	size_t const	buff_size = 128;
	char			buff[buff_size];

	ft_memset(buff, 0, sizeof(char) * buff_size);
	IFDO(0 > readlink(path, buff, buff_size), DEF_STRERR("ls", path));
	ft_printf(" -> %s", buff);
}

void		print_obj_long_format(char const *const path,
							InDirObject const *const obj)
{
	char		*fmt_str;
	t_blkcnt_t	dummy_total;

	dummy_total = 0;
	fmt_str = prepare_output_fmtstr(precalc_output(1, obj, &dummy_total));
	ft_printf(fmt_str,
		s_get_permission((char[STR_LEN_PERMISSION]) { 0 }, obj->stat->st_mode),
		obj->stat->st_nlink, getpwuid(obj->stat->st_uid)->pw_name,
		getgrgid(obj->stat->st_gid)->gr_name, obj->stat->st_size,
		s_get_date((char[STR_LEN_DATE]) { 0 }, obj->stat->st_ctime), path);
	if (S_ISLNK(obj->stat->st_mode))
		s_print_link(path);
	ft_putchar('\n');
	free(fmt_str);
}

void		print_objs_long_format(size_t const n_objs,
				InDirObject const *const objs)
{
	char		*fmt_str;
	LFCurrData	data;
	t_blkcnt_t	total;
	size_t		i;

	i = ~0ULL;
	total = 0L;
	data.date = (char[STR_LEN_DATE]) { 0 };
	data.permission = (char[STR_LEN_PERMISSION]) { 0 };
	fmt_str = prepare_output_fmtstr(precalc_output(n_objs, objs, &total));
	ft_printf("total %d\n", total);
	while (n_objs > ++i)
	{
		data = (LFCurrData) {
			s_get_date(data.date, objs[i].stat->st_ctime),
			s_get_permission(data.permission, objs[i].stat->st_mode),
			getpwuid(objs[i].stat->st_uid)->pw_name,
			getgrgid(objs[i].stat->st_gid)->gr_name };
		ft_printf(fmt_str, data.permission,
			objs[i].stat->st_nlink, data.pw_name, data.gr_name,
			objs[i].stat->st_size, data.date,
			objs[i].dirent->d_name);
		if (S_ISLNK(objs[i].stat->st_mode))
			s_print_link(objs[i].dirent->d_name);
		ft_putchar('\n');
	}
	free(fmt_str);
}
