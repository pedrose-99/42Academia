

// Esta función actualiza el mapa 
void	fill_map_conditional(t_info_map *map_info, int x, int y)
{
	if (map_info->map[y][x] == '1')
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.wall, x * 64, y* 64);
	else if (map_info->map[y][x] == 'C')
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.objects, x * 64, y* 64);
	else if (map_info->map[y][x] == '0')
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.grass,  x * 64, y* 64);
	else if (map_info->map[y][x] == 'P')
	{
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.player, x * 64, y * 64);
		map_info->pos_y = y;
		map_info->pos_x = x;
	}
	else if (map_info->map[y][x] == 'E')
		mlx_put_image_to_window(map_info->mlx, map_info->window, map_info->images.exit, x * 64, y* 64);
}

// Esta funcion analiza si hay un objeto
void	fill_map(t_info_map *map_info)
{
	int x;
	int y;

	y = 0;
	while(map_info->map[y])
	{
		x = 0;
		while(map_info->map[y][x] != '\0')
		{
			if (map_info->map[y][x] == 'C')
				map_info->objects++;
			fill_map_conditional(map_info, x, y);
			x++;
		}
		y++;
	}
}