/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:35:01 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/06 17:57:23 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*ft_aux(char *end, char *begin)
{
	while (!ft_strchr(" ><|\"\'", *end))
	{
		if (ft_strchr(" ><|", *end + 1))
			break ;
		++end;
	}
	if (ft_strchr(" ><|", *begin) && *begin)
	{
		if (*begin == *(begin + 1))
			end = end + 2;
		else
			end++;
	}
	return (end);
}

char	*ft_verify_token(char *end, char *begin)
{
	end = begin;
	if (*end == '\"')
	{
		end = ft_strchr(++end, '\"');
		if (*++end == '\0')
			return (end);
	}
	else if (*end == '\'')
	{
		end = ft_strchr(++end, '\'');
		if (*++end == '\0')
			return (end);
	}
	if (ft_strchr("=", *end))
	{
		++end;
		return (end);
	}
	return (ft_aux(end, begin));
}
