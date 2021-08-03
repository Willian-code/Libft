/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:29:45 by user              #+#    #+#             */
/*   Updated: 2021/08/03 10:23:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_word(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	*ft_fre_ret(char **ret)
{
	size_t	i;

	i = -1;
	while (ret[++i])
	{
		free(ret[i]);
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	*break_point;
	char	**ret;
	size_t	i;
	size_t	len;

	ret = (char **)ft_calloc(sizeof(char *), (ft_count_word(s, c) + 1));
	if (!s || !ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			break_point = (char *)s;
			while (*s && *s != c)
				s++;
			ret[i] = (char *)malloc((len = s - break_point + 1) * sizeof(char));
			if (!ret[i])
				return (ft_fre_ret(ret));
			ft_strlcpy(ret[i++], break_point, len);
		}
		else
			s++;
	}
	return (ret);
}
