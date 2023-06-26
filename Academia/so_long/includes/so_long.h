/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:35:51 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 16:21:17 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../utils/printf/ft_printf.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include "../utils/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define NOT_VALID_FORMAT 1
# define IMAGES_NOT_FOUND 2
# define NOT_VALID_MAP_FILE 3
# define COINS_CANT_COLLECT 4
# define NOT_REACH_EXIT 5
# define NOT_RECTANGLE 6
# define UNBOUNDED_MAP 7
# define MISSING_ITEMS 8

typedef struct s_point
{
	int	x;
	int	y;
	int	lastx;
	int	lasty;
	int	collect;
	int	exit;
}			t_point;

typedef struct s_render_images
{
	void	*exit;
	void	*waterhole;
	void	*hollow;
	void	*wall;
	void	*grass;
	void	*objects;
}	t_render_images;

typedef struct s_info_map
{
	int					height;
	int					lenght;
	int					*mlx;
	int					*window;
	int					end_game;
	int					pos_x;
	int					pos_y;
	int					init_poss;
	int					objects;
	int					exit;
	char				**map;
	int					moves;
	t_render_images		images;

}	t_info_map;

// draw.c
void			draw_take_item(t_info_map *map_info, int x, int y);
void			draw_character(t_info_map *map_info, int x, int y);
void			draw_exit(t_info_map *map_info, int x, int y);

//errors
void			check_missing_items(t_info_map *map_info);
void			print_error_exit(int exception, t_info_map *map_info);
void			print_other_errors(int error, t_info_map *map_info);

//fill_map.c
void			create_map_images_conditional(t_info_map *map_info,
					int x, int y);
void			create_map_images(t_info_map *map_info);
void			map_file_is_correct(char *file, t_info_map *map_info);
void			map_file_is_correct(char *file, t_info_map *map_info);

//load_images.c
int				load_images(t_info_map *map_info);

// render_map.c
void			player_movement(t_info_map *map_info, int x, int y);
int				key_hook(int key, t_info_map *map_info);
void			waiting_events(t_info_map *map_info);
void			map_render(t_info_map *map_info);
int				close_window(t_info_map *map_info);

//check_map.c
int				check_objects(char **map, t_info_map map_info);
int				is_rectangle(char **map, t_info_map *map_info);
t_point			check_start(char **map, t_point begin);
int				get_coins(char **map);
int				initialize_and_check_map(char const *argv[],
					t_info_map *map_info);

//check_maze_conditions.c
int				check_condition(t_point cur, char **tab);
t_point			condicion_noexit(t_point cur, char **tab);
t_point			wall_condition(t_point cur, char **tab);
t_point			condition_check_object(t_point cur, char **tab);
t_point			check_components(char **area, t_point size, t_point begin);

//check_maze.c
int				first_condition_fill(char **tab, t_point size,
					t_point cur, char to_fill);
void			fill(char **tab, t_point size, t_point cur, char to_fill);
t_point			flood_fill(char **tab, t_point size, t_point begin);
int				check_laberinto(char **map, t_info_map *map_info);

//init_maze.c
void			map_info_intializor(t_info_map *map_info, char **map);
int				check_map_init_and_end(char **map, int i, int j);
int				check_map_body(char **map, int size_columns, int size_line);
int				check_map(char **map, t_info_map *map_info);

//save_map.c
int				count_lines(char const *argv[]);
char			**malloc_columns(int num_lines);
char			**initialize_map(char const *argv[]);

//utils.c
void			free_map_info(t_info_map *map_info);
void			free_map(char **map);

//get_size.c
int				get_size_y(char **map);
int				get_size_x(char **map);
#endif