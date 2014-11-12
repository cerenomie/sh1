/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 15:22:30 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/11 14:13:50 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				ft_cd(char *a, t_params *p)
{
	char		*path;

	path = ft_strsub(a, 3, ft_strlen(a) - 3);
	if (path[0] == '~')
		path = ft_strjoin(p->v_home, ft_strsub(a, 4, ft_strlen(a) - 4));
	if (!ft_is_dir_error(path) && !ft_is_readable_error(path))
	{
		ft_add_or_replace_key(p, "PWD", path);
		return (chdir(path));
	}
	else
		return (0);
}

char			*ft_get_good_path(char *exe, t_params *p)
{
	char		**sp;
	int			counter;
	char		*ret;

	ret = NULL;
	counter = 0;
	sp = ft_strsplit(p->v_path, ':');
	if (ft_is_good_path("", exe))
		ret = exe;
	else
	{
		while (ret == NULL && sp[counter] != NULL)
		{
			if (ft_is_good_path(sp[counter], exe))
			{
				ret = ft_strjoin (sp[counter], "/");
				ret = ft_strjoin (ret, exe);
			}
			counter++;
		}
	}
	return (ret);
}
