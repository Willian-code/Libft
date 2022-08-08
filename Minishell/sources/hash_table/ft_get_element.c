/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:46:40 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/21 12:19:03 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_hnode	*ft_get_element(t_hnode *list, int find_index)
{
	int		i;
	t_hnode	*temp;

	i = -1;
	temp = list;
	while (++i != find_index)
		temp = temp->next;
	return (temp);
}
