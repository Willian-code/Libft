/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 10:29:16 by user              #+#    #+#             */
/*   Updated: 2021/08/07 10:35:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (i < n)
		{
			if (s1[i] == s2[i])
				i++;
			else
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main()
{
    char str1[] = "fresh";
    char str2[] = "refresh";
    int i, j, k;

    i = ft_strncmp(str1, "fresh", 5);
    j = ft_strncmp(str1, str2, 5);
    k = ft_strncmp(str1, "F", 1);

    printf("%d %d %d\n", i, j, k);

    return (0);
}
*/
