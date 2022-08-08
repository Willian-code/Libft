/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:40:54 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/21 10:20:55 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_init_array(t_hash *array)
{
	int	i;

	i = -1;
	while (++i < TABLE_SIZE)
	{
		array[i].head = NULL;
		array[i].tail = NULL;
	}
}
