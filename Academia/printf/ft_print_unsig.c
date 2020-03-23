#include "ft_printf.h"

void	caseu_zero_o_prec(unsigned int i, char *p, int tam_num, t_list *f)
{
	if (f->precision > 0)
		print_zero(f->precision - tam_num, f);
	else
		print_zero(f->width - tam_num, f);
	print_cosita(p, f);
}
// no se si este esta bien, ya que deberia funcionar solo como si fuese precision.
void	caseu_zero_prec(char *p, int tam_num, t_list *f)
{
	if (f->precision < tam_num)
		print_space(f->width - tam_num, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	caseu_minus_prec(char *p, unsigned int i, int tam_num, t_list *f)
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

void	caseu_width_prec(char *p, unsigned int i, int tam_num, t_list *f)
{
	if (i < 0)
		print_space(f->width - f->precision - 1, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	print_unsigned(t_list *f)
{
	unsigned int	i;
	int				tam_num;
	char			*p;

	i = va_arg(f->ap, unsigned int);
	p = ft_itoa(i);
	tam_num = ft_strlen(p);
	if ((f->zero > 0) && (f->precision > 0))
		caseu_zero_prec(p, tam_num, f);
	else if (f->minus > 0 && f->precision <= 0)
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
			caseu_zero_o_prec(i, p, tam_num, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->minus > 0 && f->precision > 0)
		caseu_minus_prec(p, i, tam_num, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		caseu_width_prec(p, i, tam_num, f);
}
/*
int		main(void)
{
	//printf("%0-6.3dg\n", 22);
	//print_spozero(22, 6, 6);
	//ft_printf("%0-6.3d", 22);
	ft_printf("%0-*.3uFIN\n", 4, 42);		// El orden en presentar los flags 0 y - es indiferente
	ft_printf("%0*.3uFIN\n", 4, -42);
	ft_printf("%-4.3uFIN\n", 42);
	ft_printf("%*uFIN\n", 4, 42);
	ft_printf("%04.1uFIN\n", 42);

	printf("%0-*.3uFIN\n", 4, 42);		// El orden en presentar los flags 0 y - es indiferente
	printf("%0*.3uFIN\n", 4, -42);
	printf("%-4.3uFIN\n", 42);
	printf("%*uFIN\n", 4, 42);
	printf("%04.1uFIN\n", 42);
}*/