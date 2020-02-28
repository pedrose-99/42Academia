/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almacendatos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 09:12:57 by pserrano          #+#    #+#             */
/*   Updated: 2020/02/28 10:42:49 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'e'|| c == 'f' || c == 'g'|| c == 'i'
		|| c == 'o'|| c == 's' || c == 'u'|| c == 'x' || c == '%' || c == 'X')
		return (1);
	else 
		return (0);
}

void	is_zero(char *cosa, t_list *f))
{
	if (cosa[f->pos] == '0')
		{
			f->zero = 1;
			f->pos++;
		}
}

void	is_minus(char *cosa, t_list *f))
{
	if (cosa[f->pos] == '-')
		{
			f->minus = 1;
			f->pos++;
		}
}

void	is_width(char *cosa, t_list *f))
{
	char	*num;
	int		i;

	i = 0;
	if (cosa[f->pos] == '*')
	{
		f->precisionfl = va_arg(f->ap, int);
	}
	else
	{
		while (ft_is_num(cosa[f->pos]))
		{
			num[i] = cosa[f->pos];
			i++;
			f->pos++;
		}
		f->width = ft_atoi(num);
	}
}

void	is_space(char *cosa, t_list *f))
{
	if (cosa[f->pos] == ' ')
		{
			f->space = 1;
			f->pos++;
		}
}

void	is_precision(char *cosa, t_list *f))
{
	char	*num;
	int		i;

	i = 0;
	if (cosa[f->pos] == '.')
	{
		f->precision = 1;
		f->pos++;
		if (cosa[f->pos] == '*')
		{
			f->precisionfl = va_arg(f->ap, int);
		}
		else
		{
			while (ft_is_num(cosa[f->pos]))
			{
				num[i] = cosa[f->pos];
				i++;
				f->pos++;
			}
			f->precisionfl = ft_atoi(num);
		}
}

void	ft_store_data(char *cosa, t_list *f)
{
	while (!is_specifier(cosa[f->pos]))
	{
		is_zero(cosa, f);
		is_minus(cosa, f)
		is_width(cosa, f);
		is_space(cosa, f);
		is_precision(cosa, f);
	}
	f->spec = cosa[f->pos]
	f->pos++;
}
 