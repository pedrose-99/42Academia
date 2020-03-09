/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_para_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:59:54 by pserrano          #+#    #+#             */
/*   Updated: 2020/03/06 09:09:00 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	print_char(t_list *f)
{
	
}*/


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

int	ft_strlen(char *str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
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


void	ft_putchar(char c, t_list *f)
{
	write(1, &c, 1);
	f->cont++;
}

void	print_zero(int	tam, t_list *f)
{
	int i;

	i = 0;
	while (i < tam)
	{
		ft_putchar('0', f);
		i++;
		f->cont++;
	}
}

void	print_space(int	tam, t_list *f)
{
	int i;

	i = 0;
	while (i < tam)
	{
		ft_putchar(' ', f);
		i++;
		f->cont++;
	}
}
void	print_cosita(char *p, t_list *f)
{
	while (*p)
	{
		ft_putchar(*p, f);
		p++;
	}
	//free(p);
}

char	*print_menos(int	num, char *p, t_list *f)
{
	if (num < 0)
	{
		ft_putchar('-', f);
		*p++;
	}
	return (p);
}
void	print_spozero(char *p, int tam_num, t_list *f) //num de espacios o zeros
{
	int		zeros;
	int		spaces;


	if (f->precision < tam_num)
		spaces = f->width - tam_num;
	else 
		spaces = f->width - f->precision;
	print_space(spaces, f);
	zeros = f->precision - tam_num;
	print_zero(zeros, f);
	print_cosita(p, f);
}

void	print_int(t_list *f)
{
	int		i;
	int		tam_num;
	char	*p;

	i = va_arg(f->ap, int);
	p = ft_itoa(i);
	tam_num = ft_strlen(p);
	if ((f->zero > 0) && (f->precision > 0) && (f->minus < 0))
		print_spozero(p, tam_num, f);
	else if ((f->minus > 0) && (f->precision > 0) && (f->zero > 0))
	{
		p = print_menos(i, p, f);
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
		if (f->precision > tam_num)
			print_space((f->width - f->precision), f);
		else
			print_space((f->width - tam_num), f);
	}
		else if ((f->minus > 0) && (f->precision > 0))
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
		if (f->precision > tam_num)
			print_space((f->width - f->precision), f);
		else
			print_space((f->width - tam_num), f);
	}
	else if (f->minus > 0)
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
	else if (f->zero > 0)
	{
		p = print_menos(i, p, f);
		print_zero((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->precision > 0)
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
	}
	else if ((f->zero < 0) && (f->minus < 0) && f->width)
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
		else if ((f->zero < 0) && (f->minus < 0) && f->precision)
	{
		print_zero((f->precision - tam_num), f);
		print_cosita(p, f);
	}
}
void init_struct(t_list *f)
{
	f->cont = 0;
	f->spec = -1;
	f->len = 0;
	f->minus = -1;
	f->precision = -1;
	f->width = -1;
	f->zero = -1;
}

int is_specifier(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's' ||
		c == 'u' || c == 'x' || c == '%' || c == 'X' || c == 'p')
		return (1);
	else
		return (0);
}

char 	*ft_store_data(char *cosa, t_list *f)
{
	while (!is_specifier(*cosa))
	{
		if (*cosa == '0')
			f->zero = 1;
		else if (*cosa == '-')
			f->minus = 1;
		else if (ft_is_num(*cosa))
		{
			f->width = ft_atoi(cosa);
			while (ft_is_num(*(cosa + 1)))
				cosa++;
		}
		else if (*cosa == '*')
			f->width = va_arg(f->ap, int);
		else if (*(cosa++) == '.')
		{
			if (*cosa == '*')
				f->precision = va_arg(f->ap, int);
			else
				f->precision = ft_atoi(cosa);
			while (!is_specifier(*(cosa + 1)))
				cosa++;
		}
		cosa++;
	}
	return (cosa);
}

int ft_printf(const char *cosa, ...)
{
	t_list f;

	//if(!(f = malloc(sizeof(t_list) *  )))
	//	return (-1);
	init_struct(&f);
	va_start(f.ap, cosa);
	while (*cosa)
	{
		if (*cosa == '%')
		{
			cosa = ft_store_data((char*)(cosa + 1), &f);
			f.spec = *(cosa++);
		/*	printf("%d\n", f.minus);
			printf("%d\n", f.zero);
			printf("%d\n", f.width);
			printf("%d\n", f.precision);*/
			print_int(&f);

		}
		else
		{
			ft_putchar(*cosa, &f);
			cosa++;
		}
	}
	return (1);
}
/*
		print_string(f);
	else if (f->spec == 'u')
		print_unsigned_int(f);
	else if (f->spec == 'x')
		print_hexa_minus(f);
	else if (f->spec == 'X')
		print_hexa_mayus(f);
	else if (f->spec == '%')
		print_porcentaje(f); //tener en cuenta las mismas cosas que la c(o eso cree raul)
}*/
int		main(void)
{
	//printf("%0-6.3dg\n", 22);
	//print_spozero(22, 6, 6);
	//ft_printf("%0-6.3d", 22);
/*	ft_printf("%-0*.3dFIN\n", 4, 42);
	ft_printf("%0*.1dFIN\n", 4, -42);
	ft_printf("%-2.3dFIN\n", 42);
	ft_printf("%*dFIN\n", 4, -42);
	ft_printf("%-04.1dFIN\n", 42);
*/	ft_printf("%-*.5dFIN\n", 7, -42);//
	ft_printf("%*.5dFIN\n", 7, -42);//
/*	ft_printf("%*.7dFIN\n", 5, 42);
	ft_printf("%0*dFIN\n", 4, -42);
	ft_printf("%-dFIN\n", 42);
	ft_printf("%-0dFIN\n", 42);
	ft_printf("%0dFIN\n", 42);
	ft_printf("%*dFIN\n", 1, 42); 
	ft_printf("%0*dFIN\n", 1, 42);
	ft_printf("%.1dFIN\n", 42);
	ft_printf("%-.1dFIN\n", 42);
	ft_printf("%-*.2dFIN\n", 2, 42);
	printf("%-0*.3dFIN\n", 4, 42);									
	printf("%0*.1dFIN\n", 4, -42);		
	printf("%-2.3dFIN\n", 42);			
	printf("%*dFIN\n", 4, -42);		
	printf("%-04.1dFIN\n", 42);			
	printf("%-*.5dFIN\n", 7, -42);
	printf("%*.5dFIN\n", 7, -42);
	printf("%*.7dFIN\n", 5, 42);
	printf("%0*dFIN\n", 4, -42);
	printf("%-dFIN\n", 42);
	printf("%-0dFIN\n", 42);
	printf("%0dFIN\n", 42);
	printf("%*dFIN\n", 1, 42); 
	printf("%0*dFIN\n", 1, 42);
	printf("%.1dFIN\n", 42);
	printf("%-.1dFIN\n", 42);
	printf("%-*.2dFIN\n", 2, 42);*/
}