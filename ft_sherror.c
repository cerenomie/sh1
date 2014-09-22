/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sherror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 23:07:46 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/27 04:15:18 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_is_file_error(char *path)
{
	int	err;

	err = 0;
	if (!ft_exists(path))
	{
		err = 1;
		ft_print_error("no such file or directory", path);
	}
	return (err);
}

int		ft_is_dir_error(char *path)
{
	int	err;

	err = 0;
	if (!ft_is_dir(path))
	{
		err = 1;
		if (ft_exists(path))
			ft_print_error("not a directory", path);
		else
			ft_print_error("no such file or directory", path);
	}
	return (err);
}

int		ft_is_readable_error(char *path)
{
	int	err;

	err = 0;
	if (!ft_can_read(path))
	{
		err = 1;
		ft_print_error("permission denied", path);
	}
	return (err);
}
