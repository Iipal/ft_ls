#include "ls.h"

void	 *free_curr_in_dir_obj(InDirObject *obj)
{
	if (obj)
	{
		if (obj->dirent)
			free(obj->dirent);
		if (obj->stat)
			free(obj->stat);
	}
	return NULL;
}
