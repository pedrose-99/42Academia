#include "config.h"

int     check_rl_borders(t_str *buffer_m)
{
    int     i;
    int     frst;
    int     lst;
    
    if (!buffer_m)
        return (0);
    
    i = 0;
    while (buffer_m)
    {
        frst = 0;

        while (buffer_m->content[frst] == ' ')
            frst++;
        lst = ft_strlen(buffer_m->content) - 1;
        while (lst > 0 && lst = ' ')
            lst--;
        if (lst <= 1
            || buffer_m->content[frst] != '1'
            || buffer_m->content[lst] != '1')
            return (0);
        buffer_m = buffer_m->next;
        i++;
    }
    return(i);    
    }
}

int     count_check_columns(char const *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '1')
			j++;
		else if (line[i] != ' ')
			return (0);
		i++;
	}
	return (j);
}

int     check_top_bottom_borders(t_str *map_buffer)
{
	int		first_line;
	int		last_line;
	t_str	*last;

	if (!map_buffer)
		return (0);
	first_line = count_check_columns(map_buffer->content);
	last = str_last(map_buffer);
	if (last)
		last_line = count_check_columns(last->content);
	else
		last_line = 0;
	if (first_line == last_line)
		return (first_line);
	return (0);
}

int     check_valid(t_config *config, t_str *map_buffer)
{
	int	i;
	int	col;

	while (map_buffer)
	{
		i = 0;
		col = 0;
		while (map_buffer->content[i])
		{
			if (!ft_in_set(map_buffer->content[i], VALID_MAP_CHARACTERS))
				return (0);
			if (map_buffer->content[i++] != ' ')
				col++;
		}
		if (col != config->columns)
			return (0);
		map_buffer = (map_buffer)->next;
	}
	return (1);
}