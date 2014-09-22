/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 21:41:15 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/27 04:24:17 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_params		*ft_get_params(int ac, char **av, char **env)
{
	t_params	*p;

	p = (t_params *)ft_memalloc(sizeof(t_params));
	p->ac = ac;
	p->av = av;
	p->v_path = "";
	p->v_home = "";
	p->v_logname = "";
	p->env = (char **)ft_memalloc(
			(ft_get_env_count(env) + 1) * sizeof(char **));
	if (ft_get_env_count (env))
		p->env = ft_memcpy(p->env, env, (ft_get_env_count(env)) * sizeof(char **));
	ft_parse_env(p);
	return (p);
}

void			ft_parse_env(t_params *p)
{
	int			counter;
	char		**elts;

	counter = 0;
	while (p->env && p->env[counter] != NULL)
	{
			if (ft_strncmp(p->env[counter], "PATH=", 5) == 0)
			{
				elts = ft_strsplit(p->env[counter], '=');
				p->v_path = elts[1];
			}
			else if (ft_strncmp(p->env[counter], "HOME=", 5) == 0)
			{
				elts = ft_strsplit(p->env[counter], '=');
				p->v_home = elts[1];
			}
			else if (ft_strncmp(p->env[counter], "LOGNAME=", 8) == 0)
			{
				elts = ft_strsplit(p->env[counter], '=');
				p->v_logname = elts[1];
			}
		counter++;
	}
}

void			ft_print_env(t_params *p)
{
	int			c;

	c = 0;
	while (p->env[c] != NULL)
	{
		ft_putendl(p->env[c]);
		c++;
	}
}

int				ft_add_env(char *action, t_params *p)
{
	char		*key;
	char		*value;
	char		**sp;

	if (action != NULL)
	{
		sp = ft_strsplit(action, ' ');
		if (sp[0] && sp[1] && sp[2])
		{
			key = sp[1];
			value = sp[2];
			ft_add_or_replace_key(p, key, value);
		}
		else if (sp[0])
			ft_print_env(p);
	}
	return (1);
}

int				ft_rm_env(char *action, t_params *p)
{
	char		*key;
	char		**sp;

	if (action != NULL)
	{
		sp = ft_strsplit(action, ' ');
		if (sp[0] && sp[1])
		{
			key = sp[1];
			ft_rm_key(p, key);
		}
	}
	return (1);
}
