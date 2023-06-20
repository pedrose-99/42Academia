#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point
  {
    int           x;
    int           y;
    int         lastx;
    int         lasty;
	int			collect;
	int			exit;
  }               t_point;

// Esta función guarda el mapa en memoria 
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

    return new;
}
 
// Esta función comprueba si los alrededores son objeto o suelo
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

// Esta función se usa cuando no hay salida
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

// Esta función se usa cuando la posición es 1
t_point	wall_condition(t_point cur, char **tab)
{
	tab[cur.y][cur.x] = 'F';
    cur.y = cur.lasty;
    cur.x = cur.lastx;
	return (cur);
}

// Esta función se usa cuando la posición es o un objeto o un 0
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

// Esta función comprueba si el laberinto tiene salida con recursividad
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

// Esta función llama a la atención función
t_point   flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin, tab[begin.y][begin.x]);
	return(begin);
}

// Función que imprime por pantalla el mapa
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
			printf("%c", area[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	return (begin);
}
// Esta función obtiene el tamaño vertical
int		get_size_y(char **map)
{
	int i;

	i = 0;
	while(map[i])
		i++;
	printf("%d\n", i);
	return (i);
}
// Esta función obtiene el tamaño horizontal
int		get_size_x(char **map)
{
	int i;

	i = 0;
	while(map[0][i])
		i++;
	printf("%d\n", i);
	return (i);
}
//Esta función obtiene la posición inicial
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

int main(void)
{
	int i;
	int j;
    t_point size;
	t_point begin;
	char**  area;
	
	size.x = 8;
	size.y = 5;
    char *zone[] = {
        "11111111",
        "1E01P1E1",
        "10C01C01",
        "10110101",
        "11111111",
    };
	area = make_area(zone, size);
	i = 0;
	int z = 0;
	z = get_size_y(area);
	int x = 0;
	x = get_size_x(area);
	while(i < size.y)
	{
        printf("%s\n", area[i]);
		i++;
	}
    printf("\n");
    //t_point begin = {7, 3, 7, 3, 0, 0};
	begin = check_start(area, begin);
	begin.collect = 0;
	begin.exit = 0;
    begin = flood_fill(area, size, begin);
	i = 0;
	begin = check_components(area, size, begin);
	printf("%d\n", begin.collect);
	printf("%d\n", begin.exit);
	int k;
	k = 0;
    while (area[k])
	{
		free(area[k]);
		k++;
	}
	system("leaks -q a.out");
    return (0);
}