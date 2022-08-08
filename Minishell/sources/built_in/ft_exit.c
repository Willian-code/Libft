/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:51:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/07 10:23:15 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	clean_exit(void)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_destroy_hash(g_data.array);
	ft_close_fds();
	ft_list_destroy(&g_data.token);
	ft_list_destroy(&g_data.cmd_table);
	return ;
}

int	ft_exit(void)
{
	int		i;
	int		aux;
	char	*tmp;

	i = -1;
	tmp = g_data.cmd_table->begin->val[1];
	if (tmp == NULL)
	{
		clean_exit();
		exit (EXIT_SUCCESS);
	}
	aux = ft_atoi(tmp);
	while (tmp[++i])
	{
		if (!ft_isdigit(tmp[i]))
		{
			printf("please dont use char my friend\n");
			exit (2);
		}
	}
	clean_exit();
	exit (aux);
}
