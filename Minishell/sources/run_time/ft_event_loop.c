/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/07 20:11:11 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_print_dir(void)
{
	char	*buf;

	buf = readline(RED"MINISHELL> "RESET);
	if (!buf)
		ft_clean_program();
	if (*buf)
	{
		add_history(buf);
		ft_strlcpy(g_data.input_string, buf, MAXINPUT);
		free(buf);
		buf = NULL;
		return (FALSE);
	}
	else
	{
		free(buf);
		return (TRUE);
	}
}

int	ft_clean_program(void)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_destroy_hash(g_data.array);
	close(g_data.fd_heredoc);
	exit(FALSE);
}

static void	ft_insert_money(void)
{
	char	*tmp;

	tmp = g_data.aux;
	while (*tmp)
	{
		if (*tmp == '\n')
			*tmp = '$';
		tmp++;
	}
}

void	ft_event_loop(void)
{
	int	flag_heredoc_simple;

	while (TRUE)
	{
		g_data.bool_expand = 0;
		flag_heredoc_simple = 0;
		ft_init_signals();
		if (ft_print_dir() || ft_set_new_line(&flag_heredoc_simple) || \
		flag_heredoc_simple)
			continue ;
		g_data.aux = g_data.input_string;
		ft_expand(g_data.aux, FALSE);
		ft_insert_money();
		ft_quoting(FALSE);
		if (!ft_tokenize())
		{
			ft_close_fds();
			ft_list_destroy(&g_data.token);
			continue ;
		}
		ft_parse();
		if (g_data.bool_expand)
			free(g_data.aux);
		ft_exececutor();
	}
}
