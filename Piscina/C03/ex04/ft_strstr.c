/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:46:47 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/20 16:54:42 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int c;

	c = 0;
	i = 0;
	if (str == '\0' || to_find == '\0')
		return (str);
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
					while (str[i + j] != ' ')
					{
						printf("%c", str[i+j]);
						j++;
					}
			}
		}
		i++;
	}
	return (0);
}
int	main()
{
	char str[] = "123456789   898";
	char to_find[] = "1234";
	ft_strstr(str, to_find);
}

