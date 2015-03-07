/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:15:03 by fteuber           #+#    #+#             */
/*   Updated: 2015/03/07 17:37:46 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_env		*ft_new(char *str)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
	{
		exit (0);
	}
	new->str = ft_strdup(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int			insert_in_new_empty_list(t_env *lst, char *str)
{
	t_env	*new;
	if ((new = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (-1);
	if ((new->str = (char *)malloc(50 * sizeof(char))) == NULL)
		return (-1);
	ft_strcpy(new->str, str);
	new->next = NULL;
	lst->debut = new;
	lst->end = new;
	lst->taille++;
	return (0);
}

int			delete(t_env *lst, int pos)
{
	t_env	*courant;
	t_env	*delete;
	int		i;

	i = 0;
	if (lst->taille <= 1 ||  pos < 1 || pos >= lst->taille)
		return (-1);
	while (i < pos)
	{
		courant = courant->next;
		i++;
	}
	delete = courant->next;
	courant->next = courant->next->next;
	if (courant->next == NULL)
		lst->end = courant;
	free (delete->str);
	free (delete);
	return (0);
}

t_env		*search(t_env *lst, int value)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->val == value)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
