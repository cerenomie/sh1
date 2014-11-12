/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 15:32:02 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/10 15:32:42 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;

	newstr = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		ft_strcat(newstr, s1);
		ft_strcat(newstr, s2);
	}
	return (newstr);
}
