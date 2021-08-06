/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:41:44 by user              #+#    #+#             */
/*   Updated: 2021/08/05 22:21:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	src_len;
	size_t	i;

	i = 0;
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
