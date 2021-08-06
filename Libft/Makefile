#SRCS    = $(wildcard ./srcs/ft_*.c)

#to compile the library
#gcc -Wall -Wextra - Werror -c ft* && ar rc libft.a *.o

#to compile the file with the library and includes
#gcc -Wall -Wextra -Werror main.c -L. -lft -I ./includes/libft.h

#to use the libft.a in compilation with your main
# ????

SOURCES			= ${wildcard ft_*.c}

OBJECTS			= ${SOURCES:.c=.o}

OBJECT_BONUS	= ${SOURCES_BONUS:.C=.O}

INCLUDE		= ${wildcard *.h}

NAME	= libft.a

CC		= clang
AR		= ar
RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= rc

INDEX		= ranlib ${NAME}


.c.o:
		${CC} ${CFLAGS} -c $< -o $@

all:    ${NAME}

$(NAME):	${OBJECTS}
				${AR} ${ARFLAGS} ${NAME} ${OBJECTS}

bonus:		${NAME} ${OBJECT_BONUS}
					${AR} ${ARFLAGS} ${NAME} ${OBJECT_BONUS}

clean:
		${RM} ${OBJECTS}

fclean:        clean
		${RM} ${NAME}

re:            fclean all

rebonus:		fclean all

runw:
	bash libft-war-machine/grademe.sh -ob

.PHONY:        all clean fclean re
