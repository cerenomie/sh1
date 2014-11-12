/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 16:39:56 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/29 15:26:22 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "get_next_line.h"

int					main(int ac, char **av, char **env)
{
	int				*fd;
	t_params		*p;

	p = ft_get_params(ac, av, env);
	ft_loop(env, fd, av, p);
	return (0);
}
