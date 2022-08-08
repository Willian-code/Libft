/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:11:53 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/06 20:56:43 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_define_token(void)
{
	t_node	*tmp;

	tmp = g_data.token->begin;
	while (tmp)
	{
		if (!ft_strcmp(tmp->val[0], "|"))
			tmp->operators = "pipe";
		else if (!ft_strcmp(tmp->val[0], "<"))
			tmp->operators = "redir_input";
		else if (!ft_strcmp(tmp->val[0], "<<"))
			tmp->operators = "here_doc";
		else if (!ft_strcmp(tmp->val[0], ">"))
			tmp->operators = "redir_output";
		else if (!ft_strcmp(tmp->val[0], ">>"))
			tmp->operators = "redir_append";
		else if (!ft_strcmp(tmp->val[0], ""))
			tmp->operators = NULL;
		else
			tmp->operators = "word";
		tmp = tmp->next;
	}
	return (ft_syntax());
}

int	ft_is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || \
	c == '\v' || c == '\f');
}

static char	*ft_add_token_list(char *end, char *begin, char *tmp)
{
	if ((*tmp == '\"' || *tmp == '\'') && \
	!(g_data.token->end != NULL && \
	!ft_strcmp(g_data.token->end->val[0], "awk") && *tmp == '\"'))
	{
		tmp[ft_strlen(tmp) - 1] = '\0';
		ft_list_add_last(g_data.token, tmp + 1);
	}
	else
		ft_list_add_last(g_data.token, tmp);
	free(tmp);
	begin = end;
	while (ft_is_space(*begin))
		++begin;
	return (begin);
}

int	ft_tokenize(void)
{
	t_token_vars	vars;

	vars.begin = g_data.aux;
	g_data.token = ft_list_create();
	vars.input_string_size = ft_strlen(g_data.aux);
	while (*vars.begin)
	{
		vars.amount_blanks = 0;
		while (ft_is_space(*vars.begin))
		{
			++vars.amount_blanks;
			++vars.begin;
		}
		vars.end = ft_verify_token(vars.end, vars.begin);
		vars.tmp = ft_substr(g_data.aux, vars.begin - g_data.aux, \
		vars.end - vars.begin);
		if (vars.input_string_size == vars.amount_blanks)
		{
			free(vars.tmp);
			return (FALSE);
		}
		vars.begin = ft_add_token_list(vars.end, vars.begin, vars.tmp);
	}
	return (ft_define_token());
}
