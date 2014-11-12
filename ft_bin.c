/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 15:22:22 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/11 14:12:47 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_exec_bin(char *bin, char **args, t_params *p)
{
	pid_t	father;
	int		status;
	int		res;

	res = 0;
	father = fork();
	if (father > 0)
		wait(&status);
	else if (father == 0)
	{
		execve(bin, args, p->env);
		exit(0);
	}
	return (res);
}
