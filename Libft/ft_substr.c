/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:41:44 by user              #+#    #+#             */
/*   Updated: 2021/07/31 22:16:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == 0)
		return (NULL);
	ft_memmove(p, s + start, len);
	p[len] = '\0';
	return (p);
}
