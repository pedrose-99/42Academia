SRCS	= main.c ft_fill_int_table.c ft_write.c ft_solve.c ft_check_errors.c ft_make_table

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CFLAGS = -Wall -Werror -Wextra

.c.o:
		cc ${CFLAGS} -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS}
					cc -o ${NAME} ${OBJS}
all:					${NAME}


clean:
				rm -f ${OBJS}

fclean:			clean
					rm -f ${NAME}

re:					fclean all

.PHONY:			all clean fclean re
