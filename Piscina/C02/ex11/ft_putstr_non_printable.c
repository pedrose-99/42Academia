/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:13:46 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/15 19:23:40 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dec_to_hex(int n)
{
	int resultado;
	int resto;
	int simbolo;
	int simboloresultado;

	resultado = n / 16;
	resto = n % 16;
	simboloresultado = resultado + ((resultado < 10) ? 48 : 87);
	simbolo = resto + ((resto < 10) ? 48 : 87);
	write(1, &simboloresultado, 1);
	write(1, &simbolo, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char temp;

	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			write(1, "\\", 1);
			temp = *str;
			dec_to_hex(temp);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
