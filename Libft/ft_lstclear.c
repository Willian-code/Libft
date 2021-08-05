/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:07:57 by user              #+#    #+#             */
/*   Updated: 2021/08/04 19:07:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	curr = *lst;
	while (curr)
	{
		tmp = curr->next;
		ft_lstdelone(curr, del);
		curr = tmp;
	}
	*lst = NULL;
}
