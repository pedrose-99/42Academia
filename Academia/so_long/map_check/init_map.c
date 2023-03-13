




// Esta función inicializa las variables de map_info
void	map_info_intializor(t_info_map *map_info, t_list *map)
{
	map_info->height = ft_lstsize(map);
	map_info->lenght = ft_strlen(map->content);
	map_info->moves = 0;
	ft_lstclear(&map, NULL);
}

void	initialize_map(t_list **map, char const *argv[])
{
	char	*buffer;
	int		fd;
	int		ctrl_line;

	buffer = NULL;
	*map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\n");
		exit(1);
	}
	ctrl_line = get_next_line(fd, &buffer);
	ft_lstadd_back(map, ft_lstnew(buffer));
	while (ctrl_line == 1)
	{
		ctrl_line = get_next_line(fd, &buffer);
		ft_lstadd_back(map, ft_lstnew(buffer));
	}
}

t_bool	initialize_andcheck_map(char const *argv[], t_info_map *map_info)
{
	t_list	*map;
	t_point begin;
	t_point	size;
	char **map_aux;
	int y;

	y = 0;
	map = NULL;
	initialize_map(&map, argv);
	saving_map_array(map, map_info);
	y = is_rectangle(map);
	if (y == 0)
		return (0);
	else if (!check_map(map))
		return (0);
	else if (!check_objects(map))
		return (0);
	map_info_intializor(map_info, map);
	//meter aqui el chechear laberinto
	if (!check_laberinto(map_info->map, map_info))
		return (0);
	initialize_map(&map, argv);
	saving_map_array(map, map_info);
	return (1);
}