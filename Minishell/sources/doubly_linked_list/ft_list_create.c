/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:21:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/10 15:35:44 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_doubly	*ft_list_create(void)
{
	t_doubly	*l;

	l = (t_doubly *)ft_calloc(1, sizeof(t_doubly));
	l->begin = NULL;
	l->end = NULL;
	l->size = 0;
	return (l);
}
