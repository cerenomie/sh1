/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 12:57:37 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/11 14:16:23 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char				*ft_strtrim(char const *s)
{
	int				d;
	int				trim_start;
	unsigned int	c;
	char			*new_str;

	d = 0;
	c = 0;
	trim_start = 0;
	new_str = ft_strnew (ft_strlen (s));
	while (c < ft_strlen (s))
	{
		if (!trim_start && ft_isblank (s[c]))
			c++;
		else
		{
			trim_start = 1;
			new_str[d++] = s[c++];
		}
	}
	while (ft_isblank (new_str[--d]))
		new_str[d] = '\0';
	return (new_str);
}
