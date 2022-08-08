/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:44:51 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/19 17:19:40 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_split_env(t_hash *array, char *envp[])
{
	int		j;
	char	*last;
	char	*tmp1;
	char	*before;

	j = -1;
	while (envp[++j])
	{
		tmp1 = ft_strchr(envp[j], '=');
		before = ft_substr(envp[j], 0, tmp1 - envp[j]);
		last = ft_substr(envp[j], tmp1 + 1 - envp[j], ft_strlen(envp[j]));
		ft_insert(array, before, last);
		free (before);
		free (last);
	}
	ft_insert(array, "?", "0");
	return (0);
}
