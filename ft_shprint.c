/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 22:16:50 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/27 04:15:38 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		ft_print_home(t_params *p)
{
	char	*pathname;
	size_t	path_size;

	path_size = sizeof(char *) * 1024;
	pathname = (char *)ft_memalloc(path_size);
	pathname = getcwd(pathname, path_size);
	ft_putstr(p->v_logname);
	ft_putstr(" in da [");
	ft_putstr(pathname);
	ft_putstr("] $ ");
}

void		ft_print_error(char *err, char *name)
{
	ft_putstr_fd("ft_minishell1: ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(name, 2);
}
