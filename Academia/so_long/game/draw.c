

int	load_images(t_info_map *map_info)
{
	int	p;
	int	j;

	map_info->images.wall = mlx_xpm_file_to_image(map_info->mlx,
			"../images/wll.xpm", &p, &j);
	map_info->images.player = mlx_xpm_file_to_image(map_info->mlx,
			"../images/hollw.xpm", &p, &j);
	map_info->images.grass = mlx_xpm_file_to_image(map_info->mlx,
			"../images/new_grass.xpm", &p, &j);
	map_info->images.exit = mlx_xpm_file_to_image(map_info->mlx,
			"../images/pozo.xpm", &p, &j);
	map_info->images.objects = mlx_xpm_file_to_image(map_info->mlx,
			"../images/token.xpm", &p, &j);
	map_info->images.player_goal = mlx_xpm_file_to_image(map_info->mlx,
			"../images/pozo.xpm", &p, &j);
	if (map_info->images.wall && map_info->images.player
		&& map_info->images.grass
		&& map_info->images.exit && map_info->images.objects)
		return (1);
	return (0);
}

void draw_collect(t_info_map *map_info, int x, int y)
{
	if (map_info->map[map_info->pos_y][map_info->pos_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.exit, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.grass, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.grass, (map_info->pos_x + x) * 64, (map_info->pos_y + y)* 64);
	mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.player, (map_info->pos_x + x) * 64, (map_info->pos_y + y)* 64);
	map_info->pos_x += x;
	map_info->pos_y += y;
	map_info->objects--;
}
// Esta funcion dibuja el personaje
void draw_character(t_info_map *map_info, int x, int y)
{
	if (map_info->map[map_info->pos_y][map_info->pos_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.exit, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.grass, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.grass, (map_info->pos_x + x) * 64, (map_info->pos_y + y)* 64);
	mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.player, (map_info->pos_x + x) * 64, (map_info->pos_y + y)* 64);
	map_info->pos_x += x;
	map_info->pos_y += y;
}

void draw_exit(t_info_map *map_info, int x, int y)
{
	if (map_info->map[map_info->pos_y][map_info->pos_x] == 'E')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.exit, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.grass, map_info->pos_x * 64, map_info->pos_y * 64);
		map_info->map[map_info->pos_y][map_info->pos_x] = '0';
	}
	mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.exit, (map_info->pos_x + x) * 64, (map_info->pos_y + y) *64);
	mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.player_goal, (map_info->pos_x + x)*64 , (map_info->pos_y + y)*64);
	map_info->pos_x += x;
	map_info->pos_y += y;
	if (map_info->objects == 0)
		close_window(map_info);
}

// Esta funcion cierra la ventana
int		close_window(t_info_map *map_info)
{
	mlx_destroy_image(map_info->mlx, map_info->images.objects);
	mlx_destroy_image(map_info->mlx, map_info->images.exit);
	mlx_destroy_image(map_info->mlx, map_info->images.player_goal);
	mlx_destroy_image(map_info->mlx, map_info->images.player);
	mlx_destroy_image(map_info->mlx, map_info->images.wall);
	mlx_destroy_image(map_info->mlx, map_info->images.grass);
	mlx_destroy_window(map_info->mlx, map_info->window);
	free_map(map_info);
	exit (0);
	return (0);
}