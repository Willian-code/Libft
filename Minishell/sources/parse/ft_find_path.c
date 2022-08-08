/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/03 18:53:34 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_clearing_remaining_paths(char **paths, char *path, int i)
{
	while (paths[++i])
		free(paths[i]);
	free(paths);
	g_data.cmd_table->end->path = path;
}

static void	handle_path(char *aux, t_var_path *vars)
{
	char	*command;

	command = NULL;
	vars->check_bin_path = 0;
	if (aux == NULL)
		return ;
	command = ft_strrchr(aux, '/');
	if (!command)
		return ;
	vars->check_bin_path = 1;
	return ;
}

static void	set_path(t_var_path *vars, char *aux)
{
	vars->path_slash = ft_strjoin(vars->paths[vars->i], "/");
	free(vars->paths[vars->i]);
	if (vars->check_bin_path)
		vars->path = ft_strdup(aux);
	else
		vars->path = ft_strjoin(vars->path_slash, aux);
	free(vars->path_slash);
	return ;
}

static void	init_vars(t_var_path *vars)
{
	vars->i = -1;
	vars->tmp = ft_find_value("PATH");
	vars->paths = ft_split(vars->tmp, ':');
	return ;
}

int	ft_find_path(char *aux)
{
	t_var_path	vars;

	handle_path(aux, &vars);
	init_vars(&vars);
	while (vars.paths != NULL && vars.paths[++vars.i])
	{
		set_path(&vars, aux);
		if (!access(vars.path, F_OK | X_OK))
		{
			ft_clearing_remaining_paths(vars.paths, vars.path, vars.i);
			return (TRUE);
		}
		free(vars.path);
	}
	free(vars.paths);
	if (vars.check_bin_path)
	{
		if (!access(aux, F_OK | X_OK))
		{
			g_data.cmd_table->end->path = ft_strdup(aux);
			return (TRUE);
		}
	}
	return (FALSE);
}
