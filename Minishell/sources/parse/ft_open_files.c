/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:01:19 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/07 10:47:09 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	handle_heredoc_operations(t_node **node, t_node *begin)
{
	g_data.here_doc = ft_strdup(begin->next->val[0]);
	(*node)->operator_input = 1;
	(*node)->operator_output = 0;
	(*node)->heredoc_bool = 1;
	return ;
}

t_node	*ft_open_files(t_node *begin, t_node *node)
{
	if (!ft_strcmp(begin->operators, "redir_input"))
	{
		close (node->fd_in);
		node->fd_in = open(begin->next->val[0], O_RDONLY, 0777);
		node->operator_input = 1;
	}
	else if (!ft_strcmp(begin->operators, "redir_output"))
	{
		close (node->fd_out);
		node->fd_out = open(begin->next->val[0], O_WRONLY | O_CREAT | \
		O_TRUNC, 0777);
		node->operator_output = 1;
	}
	else if (!ft_strcmp(begin->operators, "redir_append"))
	{
		close (node->fd_out);
		node->fd_out = open(begin->next->val[0], O_WRONLY | O_CREAT | \
		O_APPEND, 0777);
		node->operator_output = 1;
	}
	else if (!ft_strcmp(begin->operators, "here_doc"))
		handle_heredoc_operations(&node, begin);
	begin = begin->next;
	return (begin);
}
