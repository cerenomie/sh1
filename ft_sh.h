/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:11:57 by fteuber           #+#    #+#             */
/*   Updated: 2015/03/04 11:39:48 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_env t_env;

struct		s_env
{
	char	*str; /*donee*/
	t_env	*next;
	t_env	*prev;
	t_env	*debut;
	t_env	*end;
	int		taille;
};
