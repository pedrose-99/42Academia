#include "ft_printf.h"

void	caseh_zero_prec(char *p, int tam_num, t_list *f)
{
	if (f->precision < tam_num)
		print_space(f->width - tam_num, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	caseh_minus_prec(char *p, int i, int tam_num, t_list *f)
{
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
	if (i < 0 && f->precision > tam_num)
		print_space(f->width - f->precision - 1, f);
	else if (i > 0 && f->precision > tam_num)
		print_space(f->width - f->precision, f);
	else if (f->precision < tam_num)
		print_space((f->width - tam_num), f);
}

void	caseh_width_prec(char *p, unsigned int i, int tam_num, t_list *f)
{
	if (f->precision > tam_num)
		print_space(f->width - f->precision, f);
	else
		print_space(f->width - tam_num, f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

char	 *trans_hex(long int i, char c)
{
	long int			i_copy;
	char				*hex_char;
	char				*def;
	int					count;

	count = 1;
	if (c == 'x')
		hex_char = "0123456789abcdef";
	else
		hex_char = "0123456789ABCDEF";
	i_copy = i;
	while (i_copy >= 16 && (i_copy /= 16))
		count++;
	i_copy = i;
	if (!(def = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	def[count] = '\0';
	while (i_copy > 15)
	{
		--count;
		def[count] = hex_char[i_copy % 16];
		i_copy /= 16;
	}
	def[--count] = hex_char[i_copy % 16];
	return (def);
}

void	print_hexa(t_list *f)
{
	unsigned long int	i;
	int				tam_num;
	char			*p;

	i = va_arg(f->ap, unsigned long int);
	p = trans_hex(i, f->spec);
	tam_num = ft_strlen(p);
	if ((f->zero > 0) && (f->precision > 0))
		caseh_zero_prec(p, tam_num, f);
	else if (f->minus > 0 && f->precision <= 0)
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
			caseh_zero_o_prec(p, tam_num, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->minus > 0 && f->precision > 0)
		caseh_minus_prec(p, i, tam_num, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		caseh_width_prec(p, i, tam_num, f);
}

/*
	ft_printf("%-0*.3xFIN\n", 4, 42);
	ft_printf("%0*.1XFIN\n", 4, 42);
	ft_printf("%-*.3xFIN\n", 4, 42);
	ft_printf("%*XFIN\n", 4, 42);
	ft_printf("%04.1XFIN\n", 42);
		printf("hasta aqui\n");

	printf("%-0*.3xFIN\n", 4, 42);
	printf("%0*.1XFIN\n", 4, 42);
	printf("%-*.3xFIN\n", 4, 42);
	printf("%*XFIN\n", 4, 42);
	printf("%04.1XFIN\n", 42);

	*/