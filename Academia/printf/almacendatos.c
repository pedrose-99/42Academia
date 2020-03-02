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

static int	ft_is_space(char str)
{
	return (str == '\t' || str == '\v' || str == '\f' || str == '\r' ||
			str == '\n' || str == ' ') ? (1) : (0);
}

static int	ft_is_num(char str)
{
	return (str >= '0' && str <= '9') ? (1) : (0);
}
int			ft_atoi(const char *str)
{
	long int i;
	long int nb;
	long int j;

	j = 0;
	i = 0;
	nb = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		nb = -nb;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_is_num(str[i]))
	{
		j = j + ((int)str[i] - 48);
		i++;
		if (ft_is_num(str[i]))
			j = 10 * j;
	}
	j = j * nb;
	return (j);
}

int		init_struct(t_list *f)
{
	f->cont = 0;
	f->spec= 0;
	f->len = 0;
	f->minus = 0;
	f->pos = 0;
	f->precision = 0;
	f->space = 0;
	f->width = 0;
	f->zero = 0;
	f->numspaces = 0;

}

int		is_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'e'|| c == 'f' || c == 'g'|| c == 'i'
		|| c == 'o'|| c == 's' || c == 'u'|| c == 'x' || c == '%' || c == 'X')
		return (1);
	else 
		return (0);
}
void	is_zero(char *cosa, t_list *f)
{
	if (cosa[f->pos] == '0')
		{
			f->zero = 1;
			f->pos++;
		}
}

void	is_minus(char *cosa, t_list *f)
{
	if (cosa[f->pos] == '-')
		{
			f->minus = 1;
			f->pos++;
		}
}

void	is_width(char *cosa, t_list *f)
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

void	is_space(char *cosa, t_list *f)
{
	if (cosa[f->pos] == ' ')
		{
			f->space = 1;
			f->pos++;
		}
}

void	is_precision(char *cosa, t_list *f)
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
}


char*	ft_store_data(char *cosa, t_list *f)
{
	while (!is_specifier(cosa[f->pos]))
	{
		is_zero(cosa, f);
		is_minus(cosa, f);
		is_width(cosa, f);
		is_space(cosa, f);
		is_precision(cosa, f);
	}
	f->spec = cosa[f->pos];
	f->pos++;
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_printf(const char *cosa, ...)
{
	t_list	*f;

	//if(!(f = malloc(sizeof(t_list) *  )))
	//	return (-1);
	init_struct(f);
	va_start(f->ap, cosa);
	while (cosa[f->pos])
	{
		if (cosa[f->pos] == '%')
		{
			ft_store_data(&cosa[f->pos], f); // el problema es que el ptr no avanza aquí.
			printf("%d'/n", f->minus);
			printf("%d", f->zero);
			printf("%d", f->width);
			printf("%d", f->space);
			printf("%d", f->numspaces);
			printf("%d", f->precision);
			printf("%d", f->precisionfl);
			printf("%c", f->spec);
		}	
		else
		{
			ft_putchar(&cosa[f->pos]);
			f->pos++;
			f->cont++;
		}
	}
	return(1);
}
int		main(void)
{
	//printf("hola %0*.f holabuenosdoas",100, 89.24567);
	ft_printf("%0-5.8f");
}
