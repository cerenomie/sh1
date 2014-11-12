/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 16:11:10 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/11 14:16:47 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			ft_get_env_count(char **env)
{
	int		counter;

	counter = 0;
	if (env && *env)
	{
		while (env[counter] != NULL)
			counter++;
	}
	return (counter);
}

int			ft_key_exists(char **env, char *key)
{
	int		counter;

	counter = 0;
	while (env[counter] != NULL)
	{
		if (ft_strnequ(env[counter], key, ft_strlen(key)))
			return (counter);
		counter++;
	}
	return (-1);
}

int			ft_add_or_replace_key(t_params *p, char *key, char *value)
{
	int		pos;
	char	*n_str;

	n_str = ft_strdup(key);
	n_str = ft_strjoin(n_str, "=");
	n_str = ft_strjoin(n_str, value);
	pos = ft_key_exists(p->env, key);
	if (pos != -1)
	{
		p->env[pos] = n_str;
	}
	else
	{
		pos = ft_get_env_count(p->env);
		p->env = ft_realloc ((void *)p->env, sizeof(char **) * pos,
								sizeof(char **) * (pos + 2));
		p->env[pos] = n_str;
		p->env[pos + 1] = NULL;
	}
	return (1);
}

int			ft_rm_key(t_params *p, char *key)
{
	int		count;
	int		pos;

	count = ft_get_env_count(p->env);
	pos = ft_key_exists(p->env, key);
	if (pos != -1)
	{
		pos++;
		while (pos < count)
		{
			p->env[pos - 1] = p->env[pos];
			pos++;
		}
		p->env[pos - 1] = NULL;
	}
	return (1);
}

int			ft_is_good_path(char *path, char *name)
{
	char	*p;

	p = ft_strjoin (path, "/");
	p = ft_strjoin (p, name);
	if (ft_exists (p))
		return (1);
	else
		return (0);
}
