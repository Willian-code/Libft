/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_signals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:47:58 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/06 16:49:02 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

extern t_shell	g_data;

void	sigint_handler(int sig)
{
	g_data.signal = 1;
	if (g_data.pid == 0)
	{
		(void)(sig);
		if (g_data.signal_heredoc)
		{
			g_data.signal_heredoc = 0;
			ft_putstr_fd("\n", STDERR_FILENO);
			close(g_data.fd_heredoc);
		}
		else
		{
			ft_putstr_fd("\n", STDERR_FILENO);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	ft_insert(g_data.array, "?", ft_strdup("130"));
}

void	sigquit_handler(int sig)
{
	(void)(sig);
	g_data.signal = 1;
	if (g_data.pid == 0)
	{
		ft_putstr_fd("\b\b  \b\b", STDERR_FILENO);
	}
	else
	{
		ft_insert(g_data.array, "?", ft_strdup("131"));
		ft_putstr_fd("Quit (core dumped)", STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}

void	here_doc_signal(int sig)
{
	(void)sig;
	ft_insert(g_data.array, "?", "130");
	exit (130);
}

void	ft_set_signal(void (*function)(int), int sig)
{
	void	*function_pointer;

	function_pointer = function;
	signal(sig, function_pointer);
}

void	ft_init_signals(void)
{
	g_data.pid = 0;
	g_data.signal = 0;
	g_data.signal_heredoc = 0;
	g_data.fd_heredoc = dup(STDIN_FILENO);
	ft_set_signal(sigint_handler, SIGINT);
	ft_set_signal(sigquit_handler, SIGQUIT);
}
