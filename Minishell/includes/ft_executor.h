/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:08:15 by prafael-          #+#    #+#             */
/*   Updated: 2022/07/25 17:33:00 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H

# include "ft_doubly_linked_list.h"

void	ft_exececutor(void);
void	ft_create_heredoc(t_node **tmp);
void	ft_dup_out(t_node *tmp, int *fd);
void	ft_dup_in(t_node *tmp, int *fd_aux);
void	ft_exec_sys(t_node *tmp, int *fd_aux);

#endif
