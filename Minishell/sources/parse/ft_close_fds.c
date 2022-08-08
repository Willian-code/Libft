/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:22:11 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/07 10:24:37 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_close_fds(void)
{
	int	fd;

	fd = open("fd_tmp.txt", O_CREAT);
	while (fd > 2)
		close(fd--);
	unlink("fd_tmp.txt");
}
