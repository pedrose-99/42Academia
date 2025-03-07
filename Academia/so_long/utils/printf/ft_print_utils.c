/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 10:20:18 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *f)
{
	write(1, &c, 1);
	f->cont++;
}

char	*print_menos(int num, char *p, t_list *f)
{
	if (num < 0)
	{
		ft_putchar('-', f);
		p++;
	}
	return (p);
}

void	print_zero(int tam, t_list *f)
{
	int	i;

	i = 0;
	while (i < tam)
	{
		ft_putchar('0', f);
		i++;
	}
}

void	print_space(int tam, t_list *f)
{
	int	i;

	i = 0;
	while (i < tam)
	{
		ft_putchar(' ', f);
		i++;
	}
}

void	print_conversion_str(char *p, t_list *f)
{
	while (*p)
	{
		ft_putchar(*p, f);
		p++;
	}
}
