/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:44:40 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/04 14:12:24 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trim(char **str)
{
	int		i;
	char	*trim;
	char	*temp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
	{
		trim = ft_strdup(*str);
		free(*str);
		*str = 0;
	}
	else
	{
		trim = ft_substr(*str, 0, i + 1);
		temp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*str = 0;
		if (*temp)
			*str = ft_strdup(temp);
		free(temp);
	}
	return (trim);
}

char	*get_next_line(int fd)
{
	static char	*str_left[FD_SIZE];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	ssize_t		n_bytes_rd;

	n_bytes_rd = 0;
	if (fd < 0 || fd > 256 || BUFFER_SIZE < 1)
		return (NULL);
	n_bytes_rd = read(fd, buff, BUFFER_SIZE);
	while (n_bytes_rd > 0)
	{
		buff[n_bytes_rd] = '\0';
		if (!str_left[fd])
			str_left[fd] = ft_strdup("");
		temp = ft_strdup(str_left[fd]);
		free(str_left[fd]);
		str_left[fd] = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(str_left[fd], '\n'))
			break ;
		n_bytes_rd = read(fd, buff, BUFFER_SIZE);
	}
	if (n_bytes_rd < 0 || (n_bytes_rd == 0 && !str_left[fd]))
		return (NULL);
	return (trim(&str_left[fd]));
}
