/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 15:23:42 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/11 16:22:29 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = NULL;
	if ((mem = (void *)malloc(size)))
	{
		return (mem);
	}
	return (NULL);
}
