#include "ft_sh.h"

int					ft_exists(char *path)
{
	int				res;
	struct stat		*stat_l;

	res = 0;
	stat_l = (struct stat *)ft_memalloc(sizeof(struct stat));
	if (stat_l != NULL)
	{
		res = lstat(path, stat_l);
	}
	if (res != -1)
	{
		if (S_ISDIR(stat_l->st_mode) == 0)
			return (1);
		return (0);
	}
	else
		return (0);
}

int					ft_is_dir(char *path)
{
	struct stat		*stat_e;
	int				is_dir;

	is_dir = 0;
	stat_e = (struct stat *)ft_memalloc(sizeof(struct stat));
	if (stat_e)
	{
		stat(path, stat_e);
		if (stat_e)
		{
			is_dir = S_ISDIR(stat_e->st_mode);
			ft_memdel((void **) &stat_e);
		}
	}
	return (is_dir);
}

int					ft_can_read(char *path)
{
	return (access(path, R_OK) == 0);
}

int					ft_can_write(char *path)
{
	return (access(path, W_OK) == 0);
}

int					ft_can_exec(char *path)
{
	return (access(path, X_OK) == 0);
}
