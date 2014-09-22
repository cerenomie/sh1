#include "ft_sh.h"
int		ft_exec_bin(char *bin, char **args, t_params *p)
{
	pid_t	father;
	int		status;
	int		res;

	res = 0;
	father = fork();
	if  (father > 0)
		wait(&status);
	else if (father == 0)
	{
		execve(bin, args, p->env);
		exit(0);
	}
	return (res);
}
