/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:43:47 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/07 10:26:23 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# include "ft_doubly_linked_list.h"

void	ft_cd(void);
int		ft_pwd(void);
void	ft_env(void);
int		ft_exit(void);
void	ft_unset(void);
void	ft_echo(t_node *tmp);
void	ft_export(t_node *tmp);
int		ft_builtin_check(void);
void	ft_builtin(t_node *tmp);

#endif
