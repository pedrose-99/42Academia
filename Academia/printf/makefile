# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 09:57:57 by pserrano          #+#    #+#              #
#    Updated: 2020/11/01 14:55:52 by pserrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -c

FUNC = ft_print_str.c ft_print_utils_3.c ft_print_hexa.c ft_store.c \
		ft_print_int.c ft_print_utils_5.c ft_print_utils_4.c ft_print_unsig.c \
		ft_print_char.c ft_print_utils.c ft_printf.c ft_print_hexap.c \
		ft_print_utils_2.c ft_printf.c

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
