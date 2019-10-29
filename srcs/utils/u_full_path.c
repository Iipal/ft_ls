#include "ls.h"

char	*u_full_path(char *const dst,
			char const *const dir_path,
			char const *const file)
{
	register size_t	dir_path_len = ft_strlen(dir_path);

	ft_strncpy(dst, dir_path, dir_path_len);
	if (dst[dir_path_len - 1] != '/')
		dst[dir_path_len++] = '/';
	ft_strcpy(dst + dir_path_len, file);
	dst[dir_path_len + ft_strlen(file)] = '\0';
	return (dst);
}
