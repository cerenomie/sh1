#include "ft_sh.h"

#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_params		*p;

	p = ft_get_params(ac, av, env);
	ft_sh_process_loop(p);
	return (0);
}
