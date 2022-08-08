/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:42:44 by wrosendo          #+#    #+#             */
/*   Updated: 2022/05/12 20:59:42 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_child_process(t_node *tmp, int *fd, int *fd_aux)
{
	int	result;

	ft_dup_in(tmp, fd_aux);
	ft_dup_out(tmp, fd);
	close(fd[1]);
	close(fd[0]);
	result = execve(tmp->path, tmp->val, g_data.envp);
	if (result != 0)
	{
		if (!ft_find_path(tmp->val[0]))
		{
			ft_putstr_fd(tmp->val[0], STDERR_FILENO);
			ft_putstr_fd(": command not found\n", 2);
			exit(127);
		}
		else
		{
			perror(tmp->val[0]);
			exit(result);
		}
	}
}

static void	ft_parent_process(int *fd, int *fd_aux)
{
	int	status;

	status = 0;
	wait(&status);
	if (!g_data.signal)
		ft_insert(g_data.array, "?", ft_itoa(WEXITSTATUS(status)));
	*fd_aux = fd[0];
	close(fd[1]);
}

void	ft_exec_sys(t_node *tmp, int *fd_aux)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		perror("pipe ");
	pid = fork();
	if (pid == -1)
		perror("fork ");
	g_data.pid = pid;
	if (!pid)
		ft_child_process(tmp, fd, fd_aux);
	else
		ft_parent_process(fd, fd_aux);
}
