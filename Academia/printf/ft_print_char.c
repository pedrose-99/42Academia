#include "ft_printf.h"

void	print_int(t_list *f)
{
	int		i;
	int		tam_num;
	char	*p;

	i = va_arg(f->ap, int);
	p = ft_itoa(i);
	tam_num = ft_strlen(p);
	if ((f->zero > 0) && (f->precision > 0))
		case_zero_prec(i, tam_num, p, f);
	else if (f->minus > 0 && f->precision <= 0)
	{
		print_cosita(p, f);
		print_space((f->width - tam_num), f);
	}
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
			case_zero_o_prec(i, tam_num, p, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->minus > 0 && f->precision > 0)
		case_minus_prec(i, tam_num, p, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		case_width_prec(i, tam_num, p, f);
}