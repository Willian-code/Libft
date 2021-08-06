/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:55:14 by user              #+#    #+#             */
/*   Updated: 2021/08/05 17:44:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_count(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*tmp;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count(n);
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	while (--len >= neg)
	{
		tmp[len] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		tmp[len] = '-';
	return (tmp);
}

/*
int main()
{
	int i = 0;
	int tab[5] = {-2147468, -42, 0, 42, 2147483647};

	while (i < 5)
		printf("%s\n", ft_itoa(tab[i++]));

	return (0);
}
*/
