/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:47:27 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/21 12:18:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_find_key(t_hnode *list, char *key)
{
	int		retval;
	t_hnode	*temp;

	retval = 0;
	temp = list;
	while (temp != NULL)
	{
		if (!strcmp(temp->key, key))
			return (retval);
		temp = temp->next;
		retval++;
	}
	return (-1);
}
