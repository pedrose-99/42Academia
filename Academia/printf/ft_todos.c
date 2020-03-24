#include "ft_printf.h"

void	print_todos(t_list *f)
{
	char c;
	c = f->spec;

	if (c == 'd' || c == 'i')
		print_int(f);
	else if (c == 'u')
		print_unsigned(f);
	else if (c == 'x' || c == 'X')
		print_hexa(f);
	else if (c == 'p')
		print_hexap(f);
	else if (c == 'c')
		print_char(f);
	else if (c == 's')
		print_str(f);
	else if (c == '%')
		ft_putchar('%', f);
}