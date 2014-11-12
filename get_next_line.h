/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 16:40:36 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/12 16:59:13 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "ft_sh.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 10

void	ft_add_line(char **line, char **buf, long len);
void	ft_loop(int const *fd, char **line, char **buf, long *res);
int		get_next_line(int const fd, char **line);

#endif
