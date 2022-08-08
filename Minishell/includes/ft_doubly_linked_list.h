/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_linked_list.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:43:35 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/11 23:40:08 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLY_LINKED_LIST_H
# define FT_DOUBLY_LINKED_LIST_H

# include <stdlib.h>

typedef struct s_node
{
	int				fd_in;
	int				fd_out;
	int				is_builtin;
	int				heredoc_bool;
	char			*operators;
	int				operator_input;
	int				operator_output;
	char			*path;
	char			**val;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_doubly
{
	t_node	*begin;
	t_node	*end;
	size_t	size;
}t_doubly;

t_doubly	*ft_list_create(void);
t_node		*ft_node_create(char *val);
int			ft_list_is_empty(t_doubly *l);
void		ft_list_print(const t_doubly *l);
void		ft_list_destroy(t_doubly **l_ref);
void		ft_list_print2(const t_doubly *l);
void		ft_list_add_last(t_doubly *l, char *val);
void		ft_list_add_first(t_doubly *l, char *val);

#endif
