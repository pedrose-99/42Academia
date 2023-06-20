/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainprueba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:35:54 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/20 11:56:02 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// Esta función inicializa las variables de map_info
void	map_info_intializor(t_info_map *map_info, t_list *map)
{
	map_info->height = ft_lstsize(map);
	map_info->lenght = ft_strlen(map->content);
	map_info->p_direction = 2;
	map_info->moves = 0;
	ft_lstclear(&map, NULL);
}

void	free_map(t_info_map *map_info)
{
	int	i;

	i = 0;
	while (map_info->map[i])
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map);
}

void	saving_map_array(t_list *map_obsolete, t_info_map *map_info)
{
	int	j;

	j = 0;
	map_info->map = ft_calloc(ft_lstsize(map_obsolete) + 1, sizeof(char *));
	while (map_obsolete)
	{
		map_info->map[j] = ((char *)map_obsolete->content);
		map_obsolete = map_obsolete->next;
		j++;
	}
	map_info->map[j] = NULL;
}
// Esta función comprueba si el mapa contiene 1 en cada uno de sus bordes
t_bool	check_map(t_list *map)
{
	int			i;
	int			j;
	const int	endofmap = ft_lstsize(map) - 1;

	j = 0;
	i = 0;
	while (map)
	{
		if (((char *)map->content)[0] != '1' ||
			((char *)map->content)[ft_strlen(map->content) - 1] != '1')
			return (0);
		while (((char *)map->content)[i])
		{
			if ((((char *)map->content)[i] != '1' && j == 0) ||
				(((char *)map->content)[i] != '1' && j == endofmap))
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
// Esta función lee el mapa por primera vez e identifica si hay error o no
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

// Esta función compruevaba si el contenido de los tokens del mapa es correcto
t_bool	check_objects(t_list *map)
{
	int			i;
	t_info_map	map_info;

	ft_memset(&map_info, 0, sizeof(t_info_map));
	i = 0;
	while ((char *)map)
	{
		while (((char *)map->content)[i])
		{
			if (((char *)map->content)[i] == 'C')
				map_info.objects++;
			else if (((char *)map->content)[i] == 'E')
				map_info.exit++;
			else if (((char *)map->content)[i] == 'P')
				map_info.position++;
			i++;
		}
		i = 0;
		map = map->next;
	}
	if (map_info.objects >= 1 && map_info.exit == 1
		&& map_info.position == 1)
		return (1);
	return (0);
}

// Esta función comprueba si el mapa es un rectangulo o no
int	is_rectangle(t_list *map)
{
	int	aux;
	int	i;
	int y;

	i = 0;
	y = 0;
	while (((char *)map->content)[i])
		i++;
	aux = i;
	while ((char *)map)
	{
		i = 0;
		while (((char *)map->content)[i])
			i++;
		if (i != aux)
			return (0);
		map = map->next;
		y++;
	}
	return (y);
}

// Esta función ejecuta las anteriores funciones para comprobar si el mapa se guarda bien
t_bool	initialize_andcheck_map(char const *argv[], t_info_map *map_info)
{
	t_list	*map;
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
	return (1);
}

void	print_error_exit(int exception, t_info_map *map_info)
{
	if (exception == 1)
	{
		printf("Error\nNOT A VALID MAP FORMAT\n");
		free_map(map_info);
		exit (1);
	}
	else if (exception == 2)
	{
		printf("Error\nIMAGE NOT FOUND\n");
		free(map_info->mlx);
		free(map_info->win);
		free_map(map_info);
		exit (1);
	}
	else if (exception == 3)
	{
		printf("Error\nNOT A VALID MAP FILE");
		exit (1);
	}
	else if (exception == 4)
	{
		printf("Error\nNOT EXIT FOUND");
		exit (1);
	}
}

void	found_start(t_info_map *map_inf, t_list *map)
{
	int x;
	int y;
	
}
// Esta función comprueba que el tipo de archivo que es el mapa es correcto
void	valid_map_file(char const *argv, t_info_map *map_info)
{
	int	i;

	i = ft_strlen(argv);
	if (i < 5)
		print_error_exit(3, map_info);
	if (ft_strncmp(&(argv[i - 4]), ".ber", 4))
		print_error_exit(3, map_info);
}

int main(int argc, char const *argv[])
{
	t_info_map	map_info;

	if (!initialize_andcheck_map(argv, &map_info))
	{
		printf("mal");
		print_error_exit(3, &map_info);
	}
	else
	{
		printf("bien\n");
		printf("%c\n", map_info.map[4][1]);
		map_render(&map_info);
	}
	return 0;
}