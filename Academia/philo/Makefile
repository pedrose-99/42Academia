NAME = philo

SRCS = philo.c 

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
fclean:
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 