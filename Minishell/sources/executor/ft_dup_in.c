/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:31:48 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/04 20:44:37 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_dup_in(t_node *tmp, int *fd_aux)
{
	if (tmp->operator_input == 1)
		dup2(tmp->fd_in, STDIN_FILENO);
	else
		dup2(fd_aux[0], STDIN_FILENO);
}
