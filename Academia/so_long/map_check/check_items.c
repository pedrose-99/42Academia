/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:55:03 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/20 09:55:06 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

// Esta función comprueba si el mapa es un rectangulo o no
int	is_rectangle(t_list *map)
{
	int	aux;
	int	i;
	int	y;

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
				map_info.init_poss++;
			i++;
		}
		i = 0;
		map = map->next;
	}
	if (map_info.objects >= 1 && map_info.exit == 1
		&& map_info.init_poss == 1)
		return (1);
	return (0);
}