SRCS =	ft_printf.c \
	ft_parce.c \
	ft_write.c \
	write_integer.c\
	write_unsign.c\
	write_char.c\
	write_string.c\
	write_pointer.c\
	write_hex.c\
	ft_putnum.c \
	funcs_1.c\
	funcs_2.c

HEADER = ft_printft.h

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o: ${HEADER}
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${?}

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re

