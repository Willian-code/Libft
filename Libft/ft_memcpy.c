/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:54:24 by user              #+#    #+#             */
/*   Updated: 2021/08/04 18:35:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (num--)
		*cdest++ = *csrc++;
	return (dest);
}
/*
int main()
{
    char result[] = "012345678";

    printf("Antes: %s\n", result);

    ft_memcpy(result + 4, result + 2, 4 * sizeof(char));

    printf("Deopis: %s\n", result);

    return (0);
}
*/
