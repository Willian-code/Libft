/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:48:10 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/21 11:23:07 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_find_value(char *key)
{
	int		i;
	t_hnode	*temp;

	i = -1;
	while (++i < TABLE_SIZE)
	{
		temp = g_data.array[i].head;
		while (temp)
		{
			if (!ft_strcmp(temp->key, key))
				return (temp->value);
			temp = temp->next;
		}
	}
	return (NULL);
}
