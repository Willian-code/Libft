/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:27:22 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/16 14:27:2 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "ft_parse.h"
# include "ft_builtin.h"
# include "ft_executor.h"
# include "ft_hash_table.h"
# include "ft_doubly_linked_list.h"
# include "../libft/libft.h"

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/history.h>
# include <readline/readline.h>

# define TRUE 1
# define FALSE 0
# define QUOTES "Quotes not paired\n"
# define SEMICOLON "Comma is not allowed\n"
# define BACKSLASH "Escape character is not allowed\n"

# define HERE_DOC "HERE_DOC"
# define REDIR_INPUT "REDIR_INPUT"
# define REDIR_OUTPUT "REDIR_OUTPUT"
# define APPEND_OUTPUT "APPEND_OUTPUT"

# define SEPARATORS " ><\'\"|$"

# define BLACK "\e[30;1m"
# define RED "\e[31;1m"
# define GREEN "\e[32;1m"
# define YELLOW "\e[33;1m"
# define BLUE "\e[34;1m"
# define MAGENTA "\e[35;1m"
# define CYAN "\e[36;1m"
# define WHITE "\e[37;1m"
# define RESET "\e[0m"

# define MAXINPUT 1024

typedef struct s_shell
{
	char		*aux;
	char		*tmp;
	char		**envp;
	char		*here_doc;
	char		input_string[MAXINPUT];
	int			pipe_count;
	int			pid;
	int			signal;
	int			signal_heredoc;
	int			fd_heredoc;
	int			bool_expand;
	t_node		*node;
	t_hash		*array;
	t_doubly	*token;
	t_doubly	*cmd_table;
}t_shell;

extern t_shell	g_data;

void	ft_event_loop(void);
int		ft_clean_program(void);
int		ft_set_new_line(int *flag_heredoc_simple);
void	ft_error_handler(char *message);
int		ft_ctrl_d(char *s);
int		ft_quotes(int *flag_heredoc_simple);
void	ft_init_signals(void);
void	here_doc_signal(int sig);

#endif
