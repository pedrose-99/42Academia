#include "../so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// Esta funcion guarda el mapa con un malloc
//prirue eieueu
char** make_area(char** zone, t_point size)
{
    char** new;

    new = malloc(sizeof(char*) * size.y);
    for (int i = 0; i < size.y; ++i)
    {
        new[i] = malloc(size.x + 1);
        for (int j = 0; j < size.x; ++j)
            new[i][j] = zone[i][j];
        new[i][size.x] = '\0';
    }
    return (new);
}
// Esta funcion comprueba si la siguiente posición esta libre o no 
int		check_condition(t_point cur, char **tab)
{
	if(tab[cur.y][cur.x -1] == 'R' || tab[cur.y][cur.x -1] == 'W')
    {
		cur.y = cur.y;
   		cur.x = cur.x - 1;
    }
    else if (tab[cur.y][cur.x +1] == 'R' || tab[cur.y][cur.x+1] == 'W')
    {
		cur.y = cur.y;
       	cur.x = cur.x + 1;
    }
    else if (tab[cur.y - 1][cur.x] == 'R' || tab[cur.y-1][cur.x] == 'W')
    {
		cur.y = cur.y - 1;
       	cur.x = cur.x;
    }
    else if (tab[cur.y + 1][cur.x] == 'R' || tab[cur.y+1][cur.x] == 'W')
    {
		cur.y = cur.y + 1;
       	cur.x = cur.x;
    }
	else
		return (0);
	return (1);
}

// Esta funcion usa se usa cuando no se puede avanzar
t_point		condicion_noexit(t_point cur, char **tab)
{
    if ((tab[cur.y][cur.x - 1] == 'F' || tab[cur.y][cur.x - 1] == 'R' || tab[cur.y][cur.x -1] == 'W') 
		&& (tab[cur.y][cur.x + 1] == 'F' || tab[cur.y][cur.x+1] == 'R' || tab[cur.y][cur.x +1] == 'W') 
		&& (tab[cur.y - 1][cur.x] == 'F' || tab[cur.y-1][cur.x] == 'R' || tab[cur.y-1][cur.x] == 'W') 
		&& (tab[cur.y + 1][cur.x] == 'F' || tab[cur.y+1][cur.x] == 'R' || tab[cur.y+1][cur.x] == 'W'))
    {
		tab[cur.y][cur.x] = 'F';
    	if (!check_condition(cur, tab))
			exit(1);
		else
		{
			cur.lastx = cur.x;
			cur.lasty = cur.y;
		}
	}
	return (cur);
}

// Esta función se usa cuando hay un muro
t_point	wall_condition(t_point cur, char **tab)
{
	tab[cur.y][cur.x] = 'F';
    cur.y = cur.lasty;
    cur.x = cur.lastx;
	return (cur);
}

// Esta funcion se usa cuando hay un objeto
t_point	condition_check_object(t_point cur, char **tab)
{
	if (tab[cur.y][cur.x] == 'C' || tab[cur.y][cur.x] == 'W')
		tab[cur.y][cur.x] = 'W';
	else
    	tab[cur.y][cur.x] = 'R';
    cur.lastx = cur.x;
    cur.lasty = cur.y;
	return (cur);
}

// Esta función recorre el mapa con recursividad y analiza cada posición
void    fill(char **tab, t_point size, t_point cur, char to_fill)
{
    if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] == 'E' 
	|| tab[cur.y][cur.x] == 'X')
	{
		if (tab[cur.y][cur.x] == 'E')
			tab[cur.y][cur.x] = 'X';
    	return;
	}
    if (tab[cur.y][cur.x] == '1')
        cur = wall_condition(cur, tab);
    else if (tab[cur.y][cur.x] == '0' || tab[cur.y][cur.x] == 'P' || tab[cur.y][cur.x] == 'C')
		cur = condition_check_object(cur, tab);
    else if (tab[cur.y][cur.x] == 'R')
		cur = condicion_noexit(cur, tab);
    if (tab[cur.y][cur.x - 1] != 'F' && tab[cur.y][cur.x -1] != 'R' && tab[cur.y][cur.x-1] != 'W')
        fill(tab, size, (t_point){cur.x - 1, cur.y, cur.lastx, cur.lasty, cur.exit, cur.collect}, to_fill);
    if (tab[cur.y][cur.x + 1] != 'F' && tab[cur.y][cur.x +1] != 'R' && tab[cur.y][cur.x+1] != 'W')
        fill(tab, size, (t_point){cur.x + 1, cur.y, cur.lastx, cur.lasty, cur.exit, cur.collect}, to_fill);
    if (tab[cur.y - 1][cur.x] != 'F' && tab[cur.y - 1][cur.x] != 'R' && tab[cur.y-1][cur.x] != 'W')
        fill(tab, size, (t_point){cur.x, cur.y - 1, cur.lastx, cur.lasty, cur.exit, cur.collect}, to_fill);
    if (tab[cur.y + 1][cur.x] != 'F' && tab[cur.y + 1][cur.x] != 'R' && tab[cur.y+1][cur.x] != 'W')
        fill(tab, size, (t_point){cur.x, cur.y + 1, cur.lastx, cur.lasty, cur.exit, cur.collect}, to_fill);
}

// Esta función llama a la función anterior
t_point   flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin, tab[begin.y][begin.x]);
	return(begin);
}

// Esta función escribe por pantalla el mapa
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

// Esta función inicializa las variables de map_info
void	map_info_intializor(t_info_map *map_info, t_list *map)
{
	map_info->height = ft_lstsize(map);
	map_info->lenght = ft_strlen(map->content);
	map_info->moves = 0;
	ft_lstclear(&map, NULL);
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
// Esta función obtiene el tamaño vertical del mapa
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

// Esta función comprueba y obtiene la posición inicial
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

// Esta función cuenta los objetos
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

// Esta función inicializa y comprueba el mapa
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

// Esta función carga las imagenes
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

// Esta funcion dibuja el objeto
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

// Esta funcion dibuja la salida
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

// Esta funcion mueve al personaje
void	player_movement(t_info_map *map_info, int x, int y)
{
	int pos_y;
	int pos_x;

	pos_y = map_info->pos_y;
	pos_x = map_info->pos_x;
	if (map_info->map[pos_y + y][pos_x + x] != '1')
	{
		map_info->moves++;
		printf("Movements: %i\n", map_info->moves);
		if(map_info->map[pos_y + y][pos_x + x] == '0')
			draw_character(map_info, x, y);
		else if (map_info->map[pos_y + y][pos_x + x] == 'C')
			draw_collect(map_info, x, y);
		else if (map_info->map[pos_y + y][pos_x + x] == 'E')
			draw_exit(map_info, x, y);
	}
}

// Esta función analiza que boton ha sido pulsado
int		key_hook(int key, t_info_map *map_info)
{
	if (key == 53)
		close_window(map_info);
	if (map_info->end_game != 1)
	{
		if (key == 13)
			player_movement(map_info, 0, -1);
		else if (key == 0)
			player_movement(map_info, -1, 0);
		else if (key == 1)
			player_movement(map_info, 0, 1);
		else if (key == 2)
			player_movement(map_info, 1, 0);
	}
	else
		close_window(map_info);
	return (0);
}
// Esta funcion espera a que se reciba una tecla
void	waiting_events(t_info_map *map_info)
{
	mlx_key_hook(map_info->window, *key_hook, map_info);
	mlx_hook(map_info->window, 17, (1L<<8), close_window, map_info);
}

// Esta funcion inicializa la ventana y hace un bucle infinito
void	map_render(t_info_map *map_info)
{
	int screen_w;
	int screen_h;

	screen_w = map_info->lenght * 64;
	screen_h = map_info->height * 64;
	map_info->mlx = mlx_init();
	map_info->window = mlx_new_window(map_info->mlx, screen_w, screen_h, "so_long");
	if (!load_images(map_info))
		print_error_exit(2, map_info);
	fill_map(map_info);
	waiting_events(map_info);
	mlx_loop(map_info->mlx);
}

int main(int argc, char const *argv[])
{
	t_info_map	map_info;
	int i;

	if (!initialize_andcheck_map(argv, &map_info))
		printf("mal");
	else
	{
		printf("bien\n");
		map_render(&map_info);
	}
	return (0);
}

// Button1MotionMask - Button5MotionMask
//The client application receives MotionNotify events only when one or more of the specified buttons is pressed.