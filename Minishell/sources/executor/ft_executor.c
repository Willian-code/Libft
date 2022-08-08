/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:56:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/07 12:52:11 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_exec_builtin(t_node *tmp, int *fd_aux)
{
	int	fd[2];
	int	backup[2];

	backup[0] = dup(STDIN_FILENO);
	backup[1] = dup(STDOUT_FILENO);
	dup2(backup[0], STDIN_FILENO);
	dup2(backup[1], STDOUT_FILENO);
	pipe(fd);
	ft_dup_out(tmp, fd);
	ft_builtin(tmp);
	close(fd[1]);
	fd_aux[0] = fd[0];
	dup2(backup[0], STDIN_FILENO);
	dup2(backup[1], STDOUT_FILENO);
}

static t_node	*ft_verify_heredoc(void)
{
	t_node	*tmp;

	tmp = g_data.cmd_table->begin;
	while (tmp && g_data.here_doc != NULL)
	{
		if (tmp->heredoc_bool)
			return (tmp);
		if (tmp->next != NULL)
			g_data.pipe_count--;
		tmp = tmp->next;
	}
	return (g_data.cmd_table->begin);
}

static void	ft_close_clean(void)
{
	ft_close_fds();
	ft_list_destroy(&g_data.token);
	ft_list_destroy(&g_data.cmd_table);
}

static void	ft_executor_aux(t_node *tmp, int fd_aux)
{
	while (tmp)
	{
		if (tmp->is_builtin)
			ft_exec_builtin(tmp, &fd_aux);
		else
		{
			if (tmp->heredoc_bool)
				ft_create_heredoc(&tmp);
			if (tmp == NULL)
			{
				close(g_data.fd_heredoc);
				free(g_data.here_doc);
				close(fd_aux);
				return ;
			}
			ft_exec_sys(tmp, &fd_aux);
		}
		tmp = tmp->next;
		g_data.pipe_count--;
	}
}

void	ft_exececutor(void)
{
	t_node	*tmp;
	int		fd_aux;

	fd_aux = dup(STDIN_FILENO);
	tmp = ft_verify_heredoc();
	if (tmp->val[0] == NULL && tmp->heredoc_bool)
		ft_create_heredoc(&tmp);
	ft_insert(g_data.array, "?", ft_strdup("0"));
	if (tmp->val[0] == NULL)
	{
		ft_close_fds();
		return ;
	}
	ft_executor_aux(tmp, fd_aux);
	ft_close_clean();
}
