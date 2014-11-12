/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 12:55:57 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/11 14:15:09 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			ft_sh_process_loop(t_params *p)
{
	char	*buf;
	int		*brk;

	brk = ft_memalloc (1);
	*brk = 1;
	ft_print_home(p);
	while (*brk && get_next_line (0, &buf))
	{
		buf = ft_strtrim(buf);
		if (!ft_strequ(buf, ""))
			ft_read_action(brk, ft_strtrim(buf), p);
		if (*brk)
		{
			ft_parse_env(p);
			ft_print_home(p);
		}
	}
	free (brk);
	return (0);
}

int			ft_read_action(int *brk, char *action, t_params *p)
{
	if (ft_process_builtin(brk, action, p))
		return (1);
	else if (ft_process_search_exec(action, p))
		return (1);
	else
	{
		ft_print_error ("command not found", action);
		return (0);
	}
}

int			ft_process_builtin(int *brk, char *action, t_params *p)
{
	int		ret;

	ret = 1;
	if (ft_strequ(action, "exit"))
		*brk = 0;
	else if (ft_strnequ(action, "cd ", 3))
		ret = !ft_cd(action, p);
	else if (ft_strequ(action, "cd"))
		ret = !ft_cd("cd ~", p);
	else if (ft_strnequ(action, "setenv", 6))
		ft_add_env (action, p);
	else if (ft_strnequ(action, "unsetenv ", 9))
		ft_rm_env(action, p);
	else if (ft_strnequ(action, "env", 3))
		ft_print_env(p);
	else
		return (0);
	return (ret);
}

int			ft_process_search_exec(char *action, t_params *p)
{
	char	*bin;
	char	**spl;

	spl = ft_strsplit(action, ' ');
	bin = NULL;
	if (spl)
	{
		bin = ft_get_good_path(*spl, p);
		if (bin != NULL)
			ft_exec_bin(bin, spl, p);
	}
	return (bin != NULL);
}
