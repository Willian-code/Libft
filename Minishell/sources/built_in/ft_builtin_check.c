/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/12 21:39:02 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_builtin_check(void)
{
	if (!(ft_strcmp(g_data.cmd_table->end->val[0], "env")))
		return (g_data.cmd_table->end->is_builtin = 1);
	if (!(ft_strcmp(g_data.cmd_table->end->val[0], "pwd")))
		return (g_data.cmd_table->end->is_builtin = 2);
	if (!(ft_strcmp(g_data.cmd_table->end->val[0], "echo")))
		return (g_data.cmd_table->end->is_builtin = 3);
	if (!(ft_strcmp(g_data.cmd_table->end->val[0], "cd")))
		return (g_data.cmd_table->end->is_builtin = 4);
	if (!(ft_strcmp(g_data.cmd_table->end->val[0], "exit")))
		return (g_data.cmd_table->end->is_builtin = 5);
	if (!(ft_strcmp(g_data.cmd_table->end->val[0], "unset")))
		return (g_data.cmd_table->end->is_builtin = 6);
	if (!(ft_strcmp(g_data.cmd_table->end->val[0], "export")))
		return (g_data.cmd_table->end->is_builtin = 7);
	return (g_data.cmd_table->end->is_builtin = FALSE);
}
