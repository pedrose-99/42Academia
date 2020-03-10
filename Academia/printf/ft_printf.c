/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 07:47:45 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/10 12:30:34 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_putchar(char c, t_list *f)
{
	write(1, &c, 1);
	f->cont++;
}

 int		ft_typeflag1152(char c)
{
	if (cosa[i] == 'd')
	{
		i++;
		p = va_arg(ap, int);
	}
}

int		ft_case_first_num(t_list *f)
{
	va_list next;
	int		num; 
	int		tam;
	char	*numdef;


	va_copy(next, ap);
	if (cosa[f->pos++] == '0')
	{
		num = va_arg(next, int) 
		tam = ft_strlen(num);
		res = tam - cosa[f->pos];
		if (ft_isneg(num));
		{
			ft_putchar('-');
			res--;
		}
		while (res > 0)
		{
			ft_putchar('0');
			res--;
		}
		numfef = itoa((num);
		ft_putstr(numdef);
	}
	if (cosa[f->pos] == '-')
	{
		
	}
}

int		init_struct(t_list *f)
{
	f->cont = 0;
	f->flag= 0;
	f->len = 0;
	f->minus = 0;
	f->pos = 0;
	f->precision = 0;
	f->space = 0;
	f->width = 0;
	f->zero = 0;
	f->numspaces = 0;

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
		if (*cosa == '%')
			ft_store_data(cosa, f);
		else
		{
			ft_putchar(*cosa);
			cosa++;
			f->cont++;
		}
	}

}*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_zero(int	tam)
{
	int i;

	i = 0;
	while (i < tam)
	{
		ft_putchar('0');
		i++;
	}
}

void	print_space(int	tam)
{
	int i;

	i = 0;
	while (i < tam)
	{
		ft_putchar(' ');
		i++;
	}
}
int		ft_count_nb(int nb)
{
	int				count;
	unsigned int	c;

	c = 0;
	count = 0;
	if (nb < 0)
	{
		c = nb * -1;
		count++;
	}
	if (nb > 0)
		c = nb;
	while (c >= 10)
	{
		c = c / 10;
		count++;
	}
	if (c < 10)
		count++;
	return (count);
}

void	ft_putnum(char *s, int n, int l)
{
	unsigned int c;

	c = 0;
	s[l--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		c = n * -1;
	}
	if (n > 0)
		c = n;
	while (c > 10 || (c <= 10 && c != 0))
	{
		s[l--] = c % 10 + 48;
		c = c / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*new;
	int		l;

	if (n < -2147483648)
		return (NULL);
	l = ft_count_nb(n);
	new = (char*)malloc(sizeof(char) * l + 1);
	if (new == 0)
		return (NULL);
	ft_putnum(new, n, l);
	return (new);
}

int	ft_strlena(char *str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	print_cosita(char *p)
{
	while (*p)
	{
		ft_putchar(*p);
		p++;
	}
	//free(p);
}


void	print_spozero(int i, int width, int precision) //num de espacios o zeros
{
	int		tam_num;
	int		zeros;
	int		spaces;
	char	*p;

	p = ft_itoa(i);
	tam_num = ft_strlena(p);
	//printf("%d'\n" ,tam_num);
	//printf("%d'\n" ,spaces);
	print_zero((precision - tam_num));
	print_cosita(p);
	print_space(width - precision);
	zeros = precision - tam_num;
	//	printf("%d'\n" ,zeros);

}


int		main(void)
{
	printf("%.3d", 22);
	//print_spozero(22, 6, 6);
	//ft_printf("f",);
}

/*void	print_int(t_list *f)
{
	int		i;
	int		tam_num;
	char	*p;

	i = va_arg(f->ap, int);
	p = ft_itoa(i);
	tam_num = ft_strlen(p);
	if (f->zero && f->precision && (!(f->minus)))
		print_spozero(p, tam_num, f);
	else if ((f->minus > 0) && (f->precision > 0) || (f->zero > 0))
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
		print_space((f->width - f->precision), f);
	}
	else if (f->minus > 0)
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
	else if (f->zero > 0)
	{
		print_zero((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->precision  > 0)
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
	}
	else if ((f->zero < 0) && ((f->minus < 0)) && (f->width > 0))
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if ((f->zero < 0) && ((f->minus < 0)) && (f->precision > 0))
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
	}
}
si un unsigned int es negativo resta el mayor unsigned int 4,294,967,295+1 -(el numero que has puesto)
ej = %u, -1 ==== 4,294,967,295.
si 05.0d, 22 === (   22)
si 05.1d, 22 === (   22) si precision < long(num) te rellena con espacios print num
si 05.3d, 22 === (  022) si precision > long(num) pero precision < width == (espacios = width -(precision -long(num)) zeros = precision - long(num) print num
si 05.10d, 22 === (0000000022) si precision > width y > long(num) zeros = precision - long num*/
