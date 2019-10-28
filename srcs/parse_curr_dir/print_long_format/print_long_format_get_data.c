#include "ls_long_format_listing.h"

char		*plf_get_permission(char *perm_str, mode_t const st_mode_perm)
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

static char	*s_plf_append_int_to_str(char *dst, int src)
{
	char	*tmp;

	tmp = ft_itoa(src);
	ft_strcpy(dst + ft_strlen(dst), tmp);
	ft_strdel(&tmp);
	return (dst);
}

char		*plf_get_date(char *date_str, t_time_t const date_time)
{
	static struct tm			*tm;
	static char const *const	date_months[] = { "Jan ", "Feb ", "Mar ",
	"Apr ", "May ", "Jun ", "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec " };

	tm = localtime(&date_time);
	ft_memset(date_str, 0, sizeof(char) * STR_LEN_DATE);
	date_str = ft_strcpy(date_str, date_months[tm->tm_mon]);
	date_str[4] = (10 > tm->tm_mday) ? ' ' : '\0';
	date_str = s_plf_append_int_to_str(date_str, tm->tm_mday);
	date_str[ft_strlen(date_str)] = ' ';
	date_str[ft_strlen(date_str)] = (10 > tm->tm_hour) ? '0' : '\0';
	date_str = s_plf_append_int_to_str(date_str, tm->tm_hour);
	date_str[ft_strlen(date_str)] = ':';
	date_str[ft_strlen(date_str)] = (10 > tm->tm_min) ? '0' : '\0';
	date_str = s_plf_append_int_to_str(date_str, tm->tm_min);
	return (date_str);
}
