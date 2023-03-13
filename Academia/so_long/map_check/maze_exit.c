
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