
// Esta funcion mueve al personaje
void	player_movement(t_info_map *map_info, int x, int y)
{
	int pos_y;
	int pos_x;

	pos_y = map_info->pos_y;
	pos_x = map_info->pos_x;
	if (map_info->map[pos_y + y][pos_x + x] != '1')
	{
		map_info->moves++;
		printf("Movements: %i\n", map_info->moves);
		if(map_info->map[pos_y + y][pos_x + x] == '0')
			draw_character(map_info, x, y);
		else if (map_info->map[pos_y + y][pos_x + x] == 'C')
			draw_collect(map_info, x, y);
		else if (map_info->map[pos_y + y][pos_x + x] == 'E')
			draw_exit(map_info, x, y);
	}
}

int		key_hook(int key, t_info_map *map_info)
{
	if (key == 53)
		close_window(map_info);
	if (map_info->end_game != 1)
	{
		if (key == 13)
			player_movement(map_info, 0, -1);
		else if (key == 0)
			player_movement(map_info, -1, 0);
		else if (key == 1)
			player_movement(map_info, 0, 1);
		else if (key == 2)
			player_movement(map_info, 1, 0);
	}
	else
		close_window(map_info);
	return (0);
}
// Esta funcion espera a que se reciba una tecla
void	waiting_events(t_info_map *map_info)
{
	mlx_key_hook(map_info->window, *key_hook, map_info);
	mlx_hook(map_info->window, 17, (1L<<8), close_window, map_info);
}

void	map_render(t_info_map *map_info)
{
	int screen_w;
	int screen_h;

	screen_w = map_info->lenght * 64;
	screen_h = map_info->height * 64;
	map_info->mlx = mlx_init();
	map_info->window = mlx_new_window(map_info->mlx, screen_w, screen_h, "so_long");
	if (!load_images(map_info))
		print_error_exit(2, map_info);
	fill_map(map_info);
	waiting_events(map_info);
	mlx_loop(map_info->mlx);
}

int main(int argc, char const *argv[])
{
	t_info_map	map_info;
	int i;

	if (!initialize_andcheck_map(argv, &map_info))
		printf("mal");
	else
	{
		printf("bien\n");
		map_render(&map_info);
	}
	return (0);
}