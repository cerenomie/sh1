/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 16:32:30 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/10 16:33:55 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*st;

	st = s;
	while (n > 0)
	{
		st[n - 1] = '\0';
		n--;
	}
}