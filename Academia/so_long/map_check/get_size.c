int		get_size_y(char **map)
{
	int i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}
// Esta función obtiene el tamaño horizontal del mapa
int		get_size_x(char **map)
{
	int i;

	i = 0;
	while(map[0][i])
		i++;
	return (i);
}