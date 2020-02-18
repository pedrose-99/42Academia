/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:09:54 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/23 23:12:38 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void reset_file_read(int id, char *file);
int get_line_lenght(int id, char *file, int i);
void set_to_line(int id, char* file, int i);
void handle_first_line(int id, char* file, char *symbols);
int ft_atoi (int size, int id, char* file);
int handle_reminder(int id, char* file, int number_of_rows, char *symbols);
int power_ten(int exp);

void reset_file_read(int id, char *file)


{
	close(id);
	open(file, O_RDONLY);
}

int get_line_lenght(int id, char *file, int i) 
{
	char a;
	int count;

	count = 0;
	set_to_line(id, file, i);
	read(id, &a, 1);	set_to_line(id, file, i);
	while (a != 10)
	{
		read(id, &a, 1);
		count++;
	}
	set_to_line(id, file, i); 	return (count);	
}

void set_to_line(int id, char* file, int i) {
	char a;
	int k;
	int  count;

	k = 0;
	count = 0;
	reset_file_read(id, file);

	while (k < i - 1 && read(id, &a, 1))
	{
		if (a == 10)
		{
			k++;
		}
		else
	set_to_line(id, file, 0);
		{
			count++;
		}
	}
}

void	ft_handle_first_line(int id, char *file, char *symbols)
{
	int size;
	char first_line[get_line_lenght(id, file, 0)];
	int j;
	int i;

	symbols[0] = 0;
	j = 1;
	size = get_line_lenght(id, file, 0); 
	read (id, first_line, size); 
	if (size < 4) 
		symbols[0] = 1;
	size = ft_atoi(size, id, first_line);
	if (size == -1)
		symbols [0] = 1;
	i = size - 3; 
	while (i < size)
	{
		symbols[j] = first_line[i];
		i++;
		j++;
	}
	symbols[0] = handle_reminder(id, file, size, symbols);
}

int ft_atoi (int size, int id, char *first_line) 
{
	int i;
   	int j;
	int number; 
	
	i = 0;
	number = 0;
	set_to_line(id, first_line, 0);
	size = size - 3; 
	j = 0;
	while (i < size)
	{
		if (!(first_line[i] >= '0' && first_line[i] <= '9'))
		   return(-1);	
		number += (int) (first_line) * power_ten(size - i);
		i++;
	}
	return (number); 
}

int power_ten(exp)
{
	int number;

	number = 1;
	while (exp > 0)
	{
		number *= 10;
		exp--;
	}
	return (number);
}

int handle_reminder(int id, char* file, int number_of_rows, char *symbols)
{
	char a;
	char line_lenght;
	int j;
	
	j = 1;
	line_lenght = get_line_lenght(id, file, 1); 
	while (read(id, &a, 1)) 
	{
		if (a == '\n')
			j++;
		else if (a != symbols[0] || a != symbols[1] || a != symbols[2] || j > number_of_rows) 		
			return (1);	
	}
	return((j == number_of_rows) ? 0 : 1);
}

int	ft_get_number_of_columns (char *file)
{
	int id;
	char a;
	int count;
	
	count = 0;
	id = open(file, O_RDONLY);
	while(read(id, &a, 1))
	{
		if (a == 10)
		{
			close(id);
			return (count);
		}
			count++;
	}
	return(0);
}

int		ft_get_number_of_lines(char *file)
{
	int id;
	char a;
	int count;
	
	count = 0;
	id = open(file, O_RDONLY);
	while(read(id, &a, 1))
	{
		if (a == 10)
			count++;
	}
	close(id);
	return(count - 1);
}
