/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:42:54 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/07 20:59:43 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*ft_expand_last(char *tmp)
{
	while (*tmp && !ft_strchr(SEPARATORS, *tmp))
		++tmp;
	return (tmp);
}

char	*ft_getvalue(char *value)
{
	char	*content;

	content = NULL;
	content = ft_find_value(value);
	free(value);
	if (!content)
		return ("");
	return (content);
}

static void	ft_append_last(char *last, char *former)
{
	int	i;

	i = ft_strlen(last);
	if (g_data.bool_expand)
		free(g_data.aux);
	if (i != 0 && last[0] != '\0' && last[0] != '\"' && !ft_strcmp(last, "?"))
		g_data.aux = ft_strdup(former);
	else if (i != 0 && last[0] != '\0' && last[0] != '\"' && \
	!ft_strcmp(last, "?\""))
		g_data.aux = ft_strjoin(former, "\"");
	else
	{
		if (i != 0 && last[0] != '\0')
			g_data.aux = ft_strjoin(former, last);
		else
			g_data.aux = ft_strdup(former);
	}
	g_data.bool_expand = 1;
}

void	ft_chunk(char *input_string, char *tmp)
{
	char	*last;
	char	*first;
	char	*middle;
	char	*former;

	first = ft_substr(input_string, 0, tmp - input_string);
	last = ft_expand_last(tmp + 1);
	middle = ft_substr(input_string, tmp + 1 - input_string, \
	last - tmp - 1);
	middle = ft_getvalue(middle);
	former = ft_strjoin(first, middle);
	free(first);
	ft_append_last(last, former);
	free(former);
}
