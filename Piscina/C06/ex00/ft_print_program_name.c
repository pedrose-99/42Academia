/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:34:43 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/24 00:55:53 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_program_name(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	ft_print_program_name(*argv);
	ft_putchar('\n');
	return (argc);
}
