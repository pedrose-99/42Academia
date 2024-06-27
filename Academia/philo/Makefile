NAME = philo

SRCS = philo.c philo_utils.c init_struct.c print_actions.c \
		main.c check_num.c init_info.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CCFLAGS = -Werror -Wall -Wextra

all:  $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CCFLAGS) $(OBJS) -o $(NAME) 

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all

thread: CCFLAGS += -fsanitize=thread
thread: CCFLAGS += -g3
thread: re

.PHONY: all clean fclean re 