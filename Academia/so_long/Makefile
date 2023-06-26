NAME = so_long

SRCS = game/draw.c game/fill_map.c game/load_images.c \
game/render_map.c map_checker/check_map.c \
map_checker/check_maze_conditions.c map_checker/check_maze.c \
map_checker/init_map.c map_checker/save_map.c utils/utils.c \
utils/get_next_line.c utils/get_next_line_utils.c \
utils/get_size.c so_long.c game/errors.c \

OBJS		= $(SRCS:.c=.o)

PRINTF_A 	= libftprintf.a

CC			= gcc

FLAGS		= -Wall -Wextra -Werror
INCLUDE		= -lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME): $(OBJS) $(PRINTF_A)
						$(CC)  $(FLAGS) $(INCLUDE) $(OBJS) $(PRINTF_A) -o $(NAME)

$(PRINTF_A):
				make -C utils/printf
				cp utils/printf/libftprintf.a .

clean:
				make -C utils/printf clean
				rm -f $(OBJS)
fclean:
				@make -C utils/printf fclean
				rm -f libftprintf.a
				rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re