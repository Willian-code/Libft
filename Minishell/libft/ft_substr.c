/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:41:44 by user              #+#    #+#             */
/*   Updated: 2022/04/20 16:24:08 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	src_len;
	size_t	i;

	i = 0;
	p = NULL;
	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (src_len > start)
		while (s[i + start] && i < len)
			i++;
	else
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, i + 1);
	return (p);
}
