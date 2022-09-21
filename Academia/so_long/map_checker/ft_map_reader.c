#include "so_long.h"

void	get_map(t_list **map, char const *argv[])
{
	char	*buffer;
	int		fd;
	int		ctrl_line;

	buffer = NULL;
	*map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		exit(1);
	}
	ctrl_line = get_next_line(fd, &buffer);
	ft_lstadd_back(map, ft_lstnew(buffer));
	while (ctrl_line == 1)
	{
		ctrl_line = get_next_line(fd, &buffer);
		ft_lastadd_back(map, ft_lstnew(buffer));
	}
}

int		save_map(t_list *map)
{
	int i;
	int j;
	const int	endofmap = ft_lstsize(map) - 1;

	i = 0;
	j = 0;
	while (map)
	{
		if (((char *)map->content)[0] != '1' ||
			((char *)map->content)[ft_strlen(map->content) - 1] != '1')
				return (0);
		while (((char *)map->content)[i])
		{
			if ((((char *)map->content)[i] != '1' && j == 0 ||
			((char *)map->content)[i] != '1' && j == endofmap))
				return (0);
				else if (!ft_strchr("10CEP", ((char *)map->content)[i]))
					return (0);
			i++;
		}
		i = 0;
		j++;
		map = map->next;
	}
	return (1);
}

int		check_components(t_list *map)
{
	int				i;
	t_map_inf		map_inf;

	i = 0;
	ft_memset(&map_inf, 0, sizeof(t_map_inf));
	while ((char*)map)
	{
		while (((char *)map->content)[i])
		{
			if (((char *)map->content)[i] == 'C')
				map_inf.collectable++;
			else if (((char *)map->content)[i] == 'P')
				map_inf.init_position++;
			else if (((char *)map->content)[i] == 'E')
				map_inf.exit++;
			i++;
		}
		i = 0;
		map = map->next;
	}
	if (map_inf.collectable >= 1 && map_inf.init_position == 1 && map_inf.exit >= 1)
		return (1);
	return (0);
}

int		is_rectangule(t_list *map)
{
	int i;
	int aux;

	i = 0;
	while(((char*)map->content)[i])
		i++;
	aux = i;
	while((char*)map)
	{
		i = 0;
		while(((char*)map->content)[i])
			i++;
		if (aux != i)
			return (0);
		map = map->next;
	}
	return (1);
}

int		check_map(char const *argv[], t_map_inf *map_inf)
{
	t_list *map;
	
	map = NULL;
	get_map(&map, argv);
	//guardar el array del mapa
	if (!is_rectangule(map) || !save_map(map) || !check_components(map))
		return (0);
	//guardar mapa)
	map_inf->map_height = ft_lstsize(map);
	map_inf->map_lenght = ft_strlen(map->content);
	map_inf->direction = 2;
	ft_clear(&map, NULL);
	return (1); 
}
