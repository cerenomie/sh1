/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:36:35 by fteuber           #+#    #+#             */
/*   Updated: 2015/03/01 16:14:47 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			main(int ac, char **av, char **environ)
{
	unsigned short	i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
