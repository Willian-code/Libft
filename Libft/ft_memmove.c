/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:14:34 by user              #+#    #+#             */
/*   Updated: 2021/08/04 19:05:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
		return (dest);
	}
	ft_memcpy(d, s, n);
	return (dest);
}
/*
int main()
{
    char result[] = "012345678";

    printf("Antes: %s\n", result);

    ft_memmove(result + 4, result + 2, 4 * sizeof(char));

    printf("Deopis: %s\n", result);

    return (0);
}
*/

/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	char	*aux;
	char	new[n];
	size_t	i;

	i = 0;
	aux = new;
	csrc = (char *)src;
	cdest = (char *)dest;
	while (i < n)
	{
		*(aux + i) = *((const char *)csrc + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		cdest[i] = aux[i];
		i++;
	}
	return (cdest);
}
*/
