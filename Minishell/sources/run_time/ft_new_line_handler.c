/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_line_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:01:33 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/06 20:40:20 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_error_handler(char *message)
{
	ft_putstr_fd(g_data.input_string, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (!ft_strncmp(message, QUOTES, ft_strlen(message)))
		ft_putstr_fd(QUOTES, STDERR_FILENO);
	else if (!ft_strncmp(message, BACKSLASH, ft_strlen(message)))
		ft_putstr_fd(BACKSLASH, STDERR_FILENO);
	else if (!ft_strncmp(message, SEMICOLON, ft_strlen(message)))
		ft_putstr_fd(SEMICOLON, STDERR_FILENO);
}

int	ft_ctrl_d(char *s)
{
	if (!s)
	{
		ft_putstr_fd(YELLOW"bash: warning: here-document ", \
			STDOUT_FILENO);
		ft_putstr_fd("delimited by ", STDOUT_FILENO);
		ft_putstr_fd("end-of-file (wanted `", STDOUT_FILENO);
		ft_putstr_fd(g_data.here_doc, STDOUT_FILENO);
		ft_putstr_fd("')", STDOUT_FILENO);
		ft_putstr_fd("\n"RESET, STDOUT_FILENO);
		free(s);
		close(g_data.fd_heredoc);
		return (TRUE);
	}
	free(s);
	return (FALSE);
}

static void	ft_create_heredoc_simple(void)
{
	char	*s;

	unlink("here_doc.txt");
	g_data.signal_heredoc = 1;
	while (g_data.signal_heredoc)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		s = get_next_line(g_data.fd_heredoc);
		if (g_data.signal_heredoc)
		{
			if (ft_ctrl_d(s))
				break ;
		}
		else
		{
			free(s);
			s = NULL;
			break ;
		}
	}
}

static int	ft_quotes_aux(char **tmp, int *flag_heredoc_simple)
{
	if (*tmp[0] == ';' || *tmp[0] == '\\')
		return (FALSE);
	if (*tmp[0] == '\"')
		tmp[0] = ft_strchr(tmp[0] + 1, '\"');
	if (tmp[0] == NULL)
	{
		ft_create_heredoc_simple();
		*flag_heredoc_simple = 1;
		return (FALSE);
	}
	if (*tmp[0] == '\'')
		tmp[0] = ft_strchr(tmp[0] + 1, '\'');
	if (tmp[0] == NULL)
	{
		ft_create_heredoc_simple();
		*flag_heredoc_simple = 1;
		return (FALSE);
	}
	return (TRUE);
}

int	ft_quotes(int *flag_heredoc_simple)
{
	char	*tmp;

	tmp = g_data.input_string;
	while (*tmp)
	{
		if (!ft_quotes_aux(&tmp, flag_heredoc_simple))
			return (FALSE);
		++tmp;
	}
	return (TRUE);
}
