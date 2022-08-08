/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardoso <pcardoso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 02:52:01 by pcardoso          #+#    #+#             */
/*   Updated: 2022/08/03 02:52:02 by pcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_count_word(t_node *begin)
{
	t_node	*tmp;
	int		count_word;

	tmp = begin;
	count_word = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->operators, "word"))
			count_word++;
		tmp = tmp->next;
	}
	return (count_word);
}
