
// Esta función guarda el mapa en un array
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

// Esta función libera el malloc hecho anteriormente
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