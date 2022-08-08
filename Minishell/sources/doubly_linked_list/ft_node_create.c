/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:17:55 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/16 20:48:09 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_node	*ft_node_create(char *val)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	node->fd_in = 0;
	node->fd_out = 0;
	node->prev = NULL;
	node->next = NULL;
	node->path = NULL;
	node->operators = NULL;
	node->val = malloc(2 * sizeof(char *));
	node->val[0] = ft_strdup(val);
	node->val[1] = NULL;
	return (node);
}
