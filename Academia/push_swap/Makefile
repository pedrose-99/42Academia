PUSH_SWAP = push_swap
SRCS =	game_operations.c			\
		utils.c					\
		utils_2.c			\
		sort.c					\
		sort_b.c			\
		sort_a.c			\
		push_swap.c				\
		move_big_a.c

OBJS = ${SRCS:.c=.o};
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all:${PUSH_SWAP}
${PUSH_SWAP}: ${SRCS}
		${CC} ${CFLAGS} ${SRCS} -o push_swap

clean:
		${RM} ${OBJS}
fclean:	clean
		${RM} ${PUSH_SWAP}
re: fclean all
.PHONY: all re clean fclean