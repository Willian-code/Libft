NAME = ./bin/minishell
DIRNAME = ./bin
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
APP = ./apps
LIBFT_PATH = ./libft
LIBFT = libft.a
OBJDIR = ./objects
SRCDIR_PARSE = ./sources/parse
SRCDIR_HASH = ./sources/hash_table
SRCDIR_EXECUTOR = ./sources/executor
SRCDIR_BUILTIN = ./sources/built_in
SRCDIR_RUNTIME = ./sources/run_time
SRCDIR_LINKEDLIST = ./sources/doubly_linked_list
INCLUDE = ./includes
REMOVE = rm -rf

SRC_EXECUTOR += ft_executor.c ft_exec_sys.c ft_create_heredoc.c ft_dup_in.c
SRC_EXECUTOR += ft_dup_out.c
OBJEXECUTOR = $(SRC_EXECUTOR:.c=.o)
OBJECTS_EXECUTOR = $(addprefix $(OBJDIR)/, $(OBJEXECUTOR))

SRC_BUILTIN += ft_pwd.c ft_builtin_check.c ft_builtin.c ft_echo.c ft_cd.c
SRC_BUILTIN += ft_env.c ft_unset.c ft_export.c ft_exit.c
OBJBUILTIN = $(SRC_BUILTIN:.c=.o)
OBJECTS_BUILTIN = $(addprefix $(OBJDIR)/, $(OBJBUILTIN))

SRC_HASH += ft_find_key.c ft_find_value.c ft_get_element.c ft_hashcode.c
SRC_HASH += ft_init_array.c ft_insert.c ft_remove_element.c ft_split_env.c
SRC_HASH += ft_destroy_hash.c ft_create_table.c
OBJHASH = $(SRC_HASH:.c=.o)
OBJECTS_HASH = $(addprefix $(OBJDIR)/, $(OBJHASH))

SRC_LINKEDLIST += ft_list_add_first.c ft_list_create.c ft_list_destroy.c
SRC_LINKEDLIST += ft_list_is_empty.c ft_node_create.c
SRC_LINKEDLIST += ft_list_add_last.c
OBJLINKEDLIST = $(SRC_LINKEDLIST:.c=.o)
OBJECTS_LINKEDLIST = $(addprefix $(OBJDIR)/, $(OBJLINKEDLIST))

SRC_PARSE += ft_expand.c ft_parse.c ft_quoting.c ft_find_path.c ft_open_files.c
SRC_PARSE += ft_create_cmd.c ft_tokenize.c ft_syntax.c ft_verify_token.c
SRC_PARSE += ft_chunk.c ft_parse_utils.c ft_verify_awk.c ft_close_fds.c
OBJPARSE = $(SRC_PARSE:.c=.o)
OBJECTS_PARSE = $(addprefix $(OBJDIR)/, $(OBJPARSE))

SRC_RUNTIME += ft_event_loop.c ft_set_new_line.c ft_init_signals.c
SRC_RUNTIME += ft_new_line_handler.c
OBJRUNTIME = $(SRC_RUNTIME:.c=.o)
OBJECTS_RUNTIME = $(addprefix $(OBJDIR)/, $(OBJRUNTIME))

all: $(NAME)

$(NAME): $(OBJECTS_EXECUTOR) $(OBJECTS_BUILTIN) $(OBJECTS_HASH) $(OBJECTS_LINKEDLIST) $(OBJECTS_PARSE) $(OBJECTS_RUNTIME)
	$(MAKE) -C $(LIBFT_PATH)
	@mkdir -p ./bin/
	$(CC) $(APP)/main.c -o $(NAME) $(OBJECTS_EXECUTOR) $(OBJECTS_BUILTIN) $(OBJECTS_HASH) $(OBJECTS_LINKEDLIST) $(OBJECTS_PARSE) $(OBJECTS_RUNTIME) $(LIBFT_PATH)/$(LIBFT) -lreadline

$(OBJDIR)/%.o: $(SRCDIR_EXECUTOR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_BUILTIN)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_HASH)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_LINKEDLIST)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_PARSE)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_RUNTIME)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

clean:
	$(MAKE) fclean -C $(LIBFT_PATH)

fclean: clean
	$(REMOVE) $(OBJDIR)
	$(REMOVE) $(DIRNAME)

re: fclean all

v: re
	valgrind --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes --leak-check=full --suppressions=readline.supp $(NAME)

gdb: re
	gdb $(NAME)

.PHONY: bonus clean fclean re

