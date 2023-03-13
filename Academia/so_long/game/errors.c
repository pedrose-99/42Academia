

// Esta función te imprime por pantalla los errores
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
		free(map_info->window);
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