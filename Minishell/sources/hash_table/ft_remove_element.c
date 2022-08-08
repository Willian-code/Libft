/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:46:06 by wrosendo          #+#    #+#             */
/*   Updated: 2022/05/12 16:14:15 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_existing_element(t_hash *array, char *key, int index)
{
	t_hnode	*temp;

	temp = (t_hnode *)array[index].head;
	if (!strcmp(temp->key, key))
	{
		free(array[index].head->key);
		free(array[index].head->value);
		array[index].head->key = NULL;
		array[index].head->value = NULL;
		array[index].head->next = NULL;
		free(array[index].head);
		array[index].head = NULL;
		return ;
	}
	while (strcmp(temp->next->key, key))
		temp = temp->next;
	if (array[index].tail == temp->next)
	{
		temp->next = NULL;
		array[index].tail = temp;
	}
	else
		temp->next = temp->next->next;
}

void	ft_remove_element(t_hash *array, char *key)
{
	int		index;
	int		find_index;

	index = ft_hashcode(key);
	if (array[index].head == NULL)
		return ;
	else
	{
		find_index = ft_find_key((t_hnode *)array[index].head, key);
		if (find_index == -1)
			return ;
		else
			ft_existing_element(array, key, index);
	}
}
