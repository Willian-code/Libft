/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/06 19:05:26 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	update_g_data(t_node *node)
{
	if (ft_list_is_empty(g_data.cmd_table))
		g_data.cmd_table->begin = node;
	else
		g_data.cmd_table->end->next = node;
	g_data.cmd_table->end = node;
	g_data.cmd_table->size++;
	return ;
}

static int	ft_verify_cat(t_node **begin, t_node **node)
{
	int	i;

	i = 0;
	if (!ft_strcmp((*begin)->val[0], "cat"))
	{
		if ((*begin)->prev != NULL && (*begin)->prev->prev != NULL && \
		(*begin)->prev->prev->prev != NULL)
		{
			if (!ft_strcmp((*begin)->prev->operators, "pipe") && \
			!ft_strcmp((*begin)->prev->prev->operators, "word") && \
			!ft_strcmp((*begin)->prev->prev->prev->operators, "redir_output"))
			{
				if (!ft_strcmp((*begin)->next->val[0], \
				(*begin)->prev->prev->val[0]))
				{
					(*node)->val[i++] = ft_strdup((*begin)->val[0]);
					(*begin) = (*begin)->next->next;
				}
			}
		}
	}
	return (i);
}

static t_node	*ft_add_command(t_node *begin, t_node *node)
{
	int	i;

	i = 0;
	i = ft_verify_cat(&begin, &node);
	if (!i)
		i = ft_verify_awk(&begin, &node);
	while (begin)
	{
		if (!ft_strcmp(begin->operators, "word"))
			node->val[i++] = ft_strdup(begin->val[0]);
		else if (!ft_strcmp(begin->operators, "redir_input") || \
		!ft_strcmp(begin->operators, "redir_output") || \
		!ft_strcmp(begin->operators, "redir_append"))
			begin = ft_open_files(begin, node);
		else if (!ft_strcmp(begin->operators, "here_doc"))
			begin = ft_open_files(begin, node);
		else
			break ;
		begin = begin->next;
	}
	node->val[i] = NULL;
	node->prev = g_data.cmd_table->end;
	update_g_data(node);
	return (begin);
}

static t_node	*ft_new_node_table(t_node *begin)
{
	t_node	*node;
	int		count_word;

	count_word = ft_count_word(begin);
	node = malloc(1 * sizeof(t_node));
	node->prev = NULL;
	node->next = NULL;
	node->path = NULL;
	node->operator_input = FALSE;
	node->operator_output = FALSE;
	node->heredoc_bool = FALSE;
	node->fd_in = dup(STDIN_FILENO);
	node->fd_out = dup(STDOUT_FILENO);
	node->val = (char **)ft_calloc(sizeof(char *), count_word + 1);
	return (ft_add_command(begin, node));
}

void	ft_create_cmd(t_node *begin, t_node *end)
{
	while (begin != end)
		begin = ft_new_node_table(begin);
	ft_find_path(g_data.cmd_table->end->val[0]);
	ft_builtin_check();
}
