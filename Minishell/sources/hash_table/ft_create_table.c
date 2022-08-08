/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:35:53 by wrosendo          #+#    #+#             */
/*   Updated: 2022/05/10 15:43:10 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_hash	*ft_create_table(char *envp[])
{
	t_hash	*array;

	array = (t_hash *)malloc(TABLE_SIZE * sizeof(t_hash));
	ft_init_array(array);
	ft_split_env(array, envp);
	return (array);
}
