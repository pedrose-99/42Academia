#include "ft_printf.h"

void	print_char(t_list *f)
{
	char	i;

	i = va_arg(f->ap, int);
	if ((f->zero > 0 && f->precision < 0) || (f->width > 0 && f->precision < 0 && f->minus < 0))
	{
		print_space(f->width - 1, f);
		if (i == 0)
			ft_putchar('\0', f);
		else
			print_cosita(&i, f);
	}
	else if (f->minus > 0)
	{
		if (i == 0)
			ft_putchar('\0', f);
		else
			print_cosita(&i, f);
		print_space((f->width - 1), f);
	}
	else if (f->minus < 0 && f->width < 0)
	{
		if (i == 0)
			ft_putchar('\0', f);
		else
			print_cosita(&i, f);
	}
}
/*	ft_printf("%-0*cFIN\n", 4, 'x');		// añade (width - 1(char)) espacios a la dcha (ignora el 0)
	ft_printf("%0*cFIN\n", 4, 'x');		// añade (width - 1(char)) 0s a la izq
	ft_printf("%-*cFIN\n", 4, 'x');		// añade (width - 1(char)) espacios a la dcha
	ft_printf("%-cFIN\n", 'x');			// no influye el - sin otro flag
	ft_printf("%4c\n", 'x');				// añade * espacios a la izq - 1(char)
	ft_printf("%10c\n", 'x');
	printf("hasta aqui\n");
	printf("%-0*cFIN\n", 4, 'x');		// añade (width - 1(char)) espacios a la dcha (ignora el 0)
	printf("%0*cFIN\n", 4, 'x');		// añade (width - 1(char)) 0s a la izq
	printf("%-*cFIN\n", 4, 'x');		// añade (width - 1(char)) espacios a la dcha
	printf("%-cFIN\n", 'x');			// no influye el - sin otro flag
	printf("%4c\n", 'x');				// añade * espacios a la izq - 1(char)
	printf("%10c\n", 'x');	
*/