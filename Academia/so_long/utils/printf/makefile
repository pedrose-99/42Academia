NAME = libftprintf.a

CC = gcc -c

FUNC = ft_print_str.c ft_print_utils_3.c ft_store.c \
		ft_print_int.c ft_print_utils_5.c ft_print_utils_4.c \
		ft_print_char.c ft_print_utils.c ft_printf.c \
		ft_print_utils_2.c

OBJTS = ${FUNC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJTS) ft_printf.h
		@gcc -c -I $(CFLAGS) $(FUNC)
		@ar rc $(NAME) $(OBJTS)
		@ranlib $(NAME)

clean:
		@rm -f $(OBJTS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
