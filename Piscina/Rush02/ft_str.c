/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:49:21 by amunoz-g          #+#    #+#             */
/*   Updated: 2019/10/20 19:57:13 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int		ft_is_num(char str)
{
	return (str >= '0' && str <= '9') ? (1) : (0);
}

int	ft_strlen(char *str)
{
	int size;

	size = 0;
	while (str[size])
	{
		size++;
	}
	return (size);
}

int	ft_stlenblocks(char *str)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (str[i])
	{
		i++;
		if (i % 3 == 0)
			size++;
	}
	return (size);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int c;

	c = 0;
	i = 0;

	while (to_find[c])
		c++;
	while (str[i])
	{
		if (str[i] == *to_find)
		{
			j = 0;
			while (str[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					while (str[i + j] != '\n')
					{
						ft_putchar(str[i + j]);
						j++;
						if (str[i + j] == '\n')
							return (str);
					}
			}
		}
		i++;
	}
	return (str);
}

void	ft_find(char * argv, char *buffer)
{
	int size;
	int max;
	int pos;
	int size_copy;
	char *to_find;

	size_copy = 0;
	size = 0;
	max = ft_strlen(argv);
	while (argv[size])
	{
		pos = 0;
		if (max % 3 == 0 && argv[size] != '0')
		{
			to_find[pos] = argv[size];
			to_find[pos + 1] = ':';
			ft_strstr(buffer, to_find);
			to_find[pos] = '1';
			to_find[pos + 1] = '0';
			to_find[pos + 2] = '0';
			to_find[pos + 3] = ':';
			ft_strstr(buffer, to_find);
		}
		max--;
		size++;
		if (max % 3 == 2 && str[size] != '0' && argv[size] == '1')
		{
			to_find[pos] = argv[size];
			size++;
			to_find[pos + 1] = argv[size];
			to_find[pos + 2] = ':';
			ft_strstr(buffer, to_find);
			max--;
			max--;
		}	
		if (size % 3 == 2 && str[size] != '0' && argv[size] > '1')
		{
			to_find[pos] = argv[size];
			size++;
			to_find[pos + 1] = '0';
			to_find[pos + 2] = ':';
			ft_strstr(buffer, to_find);
			max--;
		}
		size++;
		size_copy = size;
		if ( size > 3)
		{
			while (size_copy > 1)
			{
				to_find[pos] = '1';
				pos++;
				size_copy--;
				while (size_copy > 0)
				{
					to_find[pos] = '0';
					pos++;
					size_copy--;
				}
				ft_strstr(buffer, to_find);
				size--;
			}
			if (size % 3 == 1 && argv[size] != '0')
			{
				to_find[0] = argv[size];
				to_find[1] = ':';
				ft_strstr(buffer, to_find);
				size--;
			}
		}
	}
}
