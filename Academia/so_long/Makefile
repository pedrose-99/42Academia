NAME = main.a

CC = gcc -Lmlx -lmlx -framework OpenGL -framework AppKit
.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

