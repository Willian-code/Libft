/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 23:04:18 by user              #+#    #+#             */
/*   Updated: 2021/08/07 11:31:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	c;

	if (dstsize == ft_strlen(dst) + 1)
		return (ft_strlen(src) + ft_strlen(dst));
	if (dstsize < ft_strlen(dst) + 2)
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	i = 0;
	while (*(src + i) != '\0' && c + 1 < dstsize)
	{
		*(dst + c) = *(src + i);
		i++;
		c++;
	}
	*(dst + c) = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
