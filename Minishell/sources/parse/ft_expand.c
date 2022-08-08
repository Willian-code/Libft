/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 07:25:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/06 17:51:42 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_front_slash(char *tmp, int *bool_quotes)
{
	if (*tmp == '\"')
		return (*bool_quotes = !*bool_quotes);
	return (*bool_quotes);
}

static char	*ft_insert_tmp(char *tmp)
{
	if (*tmp == '$')
		*tmp = '\n';
	return (++tmp);
}

void	ft_expand(char *input_string, int bool_quotes)
{
	char	*tmp;

	tmp = input_string;
	if (ft_strchr(input_string, '$') == NULL)
		return ;
	while (*tmp)
	{
		if (!ft_front_slash(tmp, &bool_quotes) && *tmp == '\'')
		{
			tmp = ft_strchr(tmp + 1, '\'');
			if (ft_strchr(tmp + 1, '$') == NULL)
				return ;
			else
				ft_expand(tmp + 1, FALSE);
		}
		if (*tmp == '$' && (*(tmp + 1) != ' ' && *(tmp + 1) != '\0' && \
		*(tmp + 1) != '\'' && *(tmp + 1) != '\"'))
		{
			ft_chunk(input_string, tmp);
			break ;
		}
		else if (*tmp)
			tmp = ft_insert_tmp(tmp);
	}
	ft_expand(g_data.aux, FALSE);
}
