/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_awk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:54:20 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/06 17:54:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_verify_awk(t_node **begin, t_node **node)
{
	int	i;

	i = 0;
	if (!ft_strcmp((*begin)->val[0], "awk") && (*begin)->next != NULL)
	{
		if (*(*begin)->next->val[0] == '\"')
		{
			(*node)->val[i++] = ft_strdup("cat");
			(*begin) = (*begin)->next->next;
		}
	}
	return (i);
}
