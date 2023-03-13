

t_point	check_components(char **area, t_point size, t_point begin)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(j < size.y)
	{
		i = 0;
		while(i <= size.x)
		{
			if (area[j][i] == 'W')
				begin.collect++;
			if (area[j][i] == 'X')
				begin.exit++;
			i++;
		}
		j++;
	}
	return (begin);
}

t_point	check_start(char **map, t_point begin)
{
	int i;
	int j;

	j = 0;
	while(map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				begin.x = i;
				begin.y = j;
				begin.lastx = i;
				begin.lasty = j;
			}
			i++;
		}
		j++;
	}
	return(begin);
}

int		get_coins(char **map)
{
	int i;
	int j;
	int z;

	j = 0;
	z = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				z++;
			i++;
		}
		j++;
	}
	return (z);
}

int		check_laberinto(char **map, t_info_map *map_info)
{
	t_point begin;
	t_point size;
	int z;
	int i = 0;
	//meter aqui el chechear laberinto
	size.x = get_size_x(map);
	size.y = get_size_y(map);
	z = get_coins(map);
	begin = check_start(map, begin);
	begin.collect = 0;
	begin.exit = 0;
	begin = flood_fill(map, size, begin);
	begin = check_components(map, size, begin);
	if (begin.collect != z)
	{
		printf("No se recogen tos los coins\n");
		return (0);
	}
	if (begin.exit != 1)
	{
		printf("No se puede llegar a la salida\n");
		return (0);
	}
	return (1);
}