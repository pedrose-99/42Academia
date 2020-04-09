# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro <pedro@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 09:57:57 by pserrano          #+#    #+#              #
#    Updated: 2020/04/09 10:25:15 by pedro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -c

FUNC = *.c

OBJTS = *.o

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
