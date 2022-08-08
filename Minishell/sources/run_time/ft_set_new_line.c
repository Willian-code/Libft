/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:04:17 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/07 10:30:55 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_backslash_semicolon(void)
{
	char	*tmp;

	tmp = g_data.input_string;
	while (*tmp)
	{
		if (*tmp == '\\')
		{
			ft_error_handler(BACKSLASH);
			return (FALSE);
		}
		if (*tmp == ';')
		{
			ft_error_handler(SEMICOLON);
			return (FALSE);
		}
		++tmp;
	}
	return (TRUE);
}

void	ft_set_zero(void)
{
	char	*tmp;

	tmp = g_data.input_string;
	while (*tmp)
		*tmp++ = '\0';
	close(g_data.fd_heredoc);
}

int	ft_set_new_line(int *flag_heredoc_simple)
{
	if (!ft_quotes(flag_heredoc_simple) && !ft_backslash_semicolon())
	{
		ft_set_zero();
		return (TRUE);
	}
	else
		return (FALSE);
}
