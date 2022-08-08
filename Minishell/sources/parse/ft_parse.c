/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:53:01 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/12 21:42:01 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_parse(void)
{
	t_node	*end;
	t_node	*begin;

	g_data.pipe_count = 0;
	end = g_data.token->begin;
	begin = g_data.token->begin;
	g_data.cmd_table = ft_list_create();
	while (end != NULL)
	{
		if (!ft_strcmp(end->operators, "pipe"))
		{
			ft_create_cmd(begin, end);
			begin = end->next;
			g_data.pipe_count++;
		}
		end = end->next;
	}
	ft_create_cmd(begin, end);
}
