/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 12:52:19 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/10 15:37:59 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			ft_strpos(const char *s1, const char *s2)
{
	char	*s1_;
	char	*s2_;
	int		l;
	int		counter;

	counter = 0;
	s1_ = (char *)s1;
	s2_ = (char *)s2;
	l = ft_strlen(s2_);
	while (*s1_ != '\0')
	{
		if (ft_strncmp(s1_, s2_, l) == 0)
			return (counter);
		s1_++;
		counter++;
	}
	return (counter);
}
