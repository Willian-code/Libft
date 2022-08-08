/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/07 10:22:23 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include "ft_doubly_linked_list.h"

typedef struct s_var_path
{
	int		i;
	int		check_bin_path;
	char	*tmp;
	char	*path;
	char	**paths;
	char	*path_slash;
}t_var_path;

typedef struct s_token_vars
{
	char	*end;
	char	*tmp;
	char	*begin;
	int		amount_blanks;
	int		input_string_size;
}t_token_vars;

void	ft_parse(void);
int		ft_syntax(void);
int		ft_tokenize(void);
void	ft_destroy_list(void);
int		ft_find_path(char *aux);
void	ft_quoting(int bool_quotes);
void	ft_create_cmd(t_node *begin, t_node *end);
t_node	*ft_open_files(t_node *begin, t_node *node);
void	ft_expand(char *input_string, int bool_quotes);
int		ft_count_word(t_node *begin);
char	*ft_verify_token(char *end, char *begin);
void	ft_chunk(char *input_string, char *tmp);
int		ft_verify_awk(t_node **begin, t_node **node);
void	ft_close_fds(void);

#endif
