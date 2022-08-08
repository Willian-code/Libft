/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:26:39 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/12 15:08:33 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_list_destroy(t_doubly **l_ref)
{
	int			i;
	t_doubly	*l;
	t_node		*p;
	t_node		*aux;

	aux = NULL;
	l = *l_ref;
	p = l->begin;
	while (p != NULL)
	{
		i = 0;
		aux = p;
		p = p->next;
		while (aux->val[i] != NULL)
			free(aux->val[i++]);
		free(aux->val);
		free(aux->path);
		free(aux);
	}
	free(l);
	*l_ref = NULL;
}
