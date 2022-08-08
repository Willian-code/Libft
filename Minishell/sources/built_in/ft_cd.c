/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:50:11 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/06 17:47:30 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_only_cd(void)
{
	if (ft_find_value("HOME") != NULL)
	{
		if (chdir(ft_find_value("HOME")) == -1)
			perror("");
	}
	else
	{
		if (chdir(ft_find_value("PWD")) == -1)
			perror("");
	}
}

void	ft_cd(void)
{
	int	i;

	i = -1;
	while (g_data.cmd_table->begin->val[++i])
		;
	if (i <= 2)
	{
		if (i == 1)
			ft_only_cd();
		else if (i == 2)
		{
			if (chdir(g_data.cmd_table->begin->val[1]) == -1)
				perror("");
		}
	}
	else
		ft_putstr_fd("too many arguments\n", STDOUT_FILENO);
}
