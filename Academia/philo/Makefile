NAME = philo

SRCS = philo.c utils/philo_utils.c srcs/init_struct.c utils/print_actions.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CCFLAGS = -Werror -Wall -Wextra #-g3 -fsanitize=thread

all:  $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
fclean:
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 