/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:07:59 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/06 16:11:28 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_verify_pipe(t_node *tmp)
{
	if (tmp->prev == NULL || tmp->next == NULL || \
	tmp->next->operators == NULL)
	{
		ft_putendl_fd("Syntax error", STDERR_FILENO);
		return (FALSE);
	}
	return (TRUE);
}

static int	ft_verify_operator(t_node *tmp)
{
	if (tmp->next == NULL || ft_strcmp(tmp->next->operators, "word"))
	{
		ft_putendl_fd("Syntax error", STDERR_FILENO);
		return (FALSE);
	}
	return (TRUE);
}

int	ft_syntax(void)
{
	t_node	*tmp;

	tmp = g_data.token->begin;
	while (tmp)
	{
		if (!ft_strcmp(tmp->operators, "pipe"))
		{
			if (!ft_verify_pipe(tmp))
				return (FALSE);
		}
		else if (!ft_strcmp(tmp->operators, "redir_output") || !ft_strcmp \
		(tmp->operators, "redir_append") || !ft_strcmp(tmp->operators, \
		"redir_input") || !ft_strcmp(tmp->operators, "here_doc"))
		{
			if (!ft_verify_operator(tmp))
				return (FALSE);
		}
		else if (tmp->operators == NULL)
		{
			if (tmp->next == NULL || tmp->prev == NULL)
				return (FALSE);
		}
		tmp = tmp->next;
	}
	return (TRUE);
}
