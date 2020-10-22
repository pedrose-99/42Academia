#include "ft_printf.h"

void	print_string(char *i, int tam_str, t_list *f)
{
	int p;

	p = 0;
	while (p < tam_str)
	{
		ft_putchar(i[p], f);
		p++;
	}
}
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	minus_precs(int tam_str, char *i, t_list *f)
{
	int tam_def;

	if (tam_str <= f->precision || f->precision < 0)
		tam_def = tam_str;
	else
		tam_def = f->precision;
	print_string(i, tam_def, f);
	print_space(f->width - tam_def, f);
}

void	zero_precs(int tam_str, char *i, t_list *f)
{
	int tam_def;

	if (tam_str <= f->precision || f->precision < 0)
		tam_def = tam_str;
	else
		tam_def = f->precision;
	print_space(f->width - tam_def, f);
	print_string(i, tam_def, f);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (s1[j])
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return ((char*)s2);
}

char	*handle_string(char *s)
{
	if (s)
		return (ft_strdup(s));
	else
		return (ft_strdup("(null)"));
}

void	print_str(t_list *f)
{
	char	*i;	
	int		tam_str;

	i = va_arg(f->ap, char*);
	i = handle_string(i);
	tam_str = ft_strlen(i);
	if ((f->zero > 0 && f->precision < 0) || (f->width > 0 && f->precision < 0 && f->minus < 0))
	{
		print_space(f->width - tam_str, f);
		print_cosita(i, f);
	}
	else if (f->precision == 0)
		print_space(f->width, f);
	else if (f->minus > 0 && f->precision < 0)
	{
		print_cosita(i, f);
		print_space((f->width - tam_str), f);
	}
	else if ((f->zero > 0 && f->precision > 0) || (f->width > 0 && f->precision > 0 && f->minus < 0))
		zero_precs(tam_str, i, f);
	else if (f->minus > 0 && f->precision > 0)
		minus_precs(tam_str, i, f);
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_cosita(i, f);
	else if (f->minus < 0 && f->width < 0 && f->precision > 0)
	{
		if (tam_str < f->precision)
			print_string(i,tam_str, f);
		else
			print_string(i,f->precision, f);
	}
}

/*
	ft_printf("%0*.7sFIN\n", 10, "hola");		// La precisión escoge solo los x primeros caracteres y el * añade el width
										// sobrante a la izq en forma de 0s
	ft_printf("%-0*.2sFIN\n", 4, "hola");		// La precisión escoge solo los x primeros caracteres y el * añade el width
										// sobrante a la dcha en forma de espacios
	ft_printf("%-*sFIN\n", 6, "hola");		// añade (width - len(char *)) a la dcha
	ft_printf("%-*.2sFIN\n", 4, "hola");	// . coge los 2 primeros char y añade (width - len(char *)) espacios a dcha
	ft_printf("%*.2sFIN\n", 4, "hola");	// . coge los 2 primeros char y añade (width - len(char *)) espacios a izq
	ft_printf("%*sFIN\n", 6, "hola");			// añade (width - len(char *)) espacios a la izq
	ft_printf("%-.2sFIN\n", "hola");
	ft_printf("%0.2sFIN\n", "hola");
		// Estos ejemplos de flags no influyen en la cadena
	ft_printf("X%-sFIN\n", "hola");
	ft_printf("X%0sFIN\n", "hola");
	ft_printf("X%-0sFIN\n", "hola"); // no mirar el printf no funcions con -0
	ft_printf("X%0.7sFIN\n", "hola");
	ft_printf("X%-.7sFIN\n", "hola");
	printf("hasta aqui\n");
	printf("%0*.7sFIN\n", 10, "hola");		// La precisión escoge solo los x primeros caracteres y el * añade el width
										// sobrante a la izq en forma de 0s
	printf("%-0*.2sFIN\n", 4, "hola");		// La precisión escoge solo los x primeros caracteres y el * añade el width
										// sobrante a la dcha en forma de espacios
	printf("%-*sFIN\n", 6, "hola");		// añade (width - len(char *)) a la dcha
	printf("%-*.2sFIN\n", 4, "hola");	// . coge los 2 primeros char y añade (width - len(char *)) espacios a dcha
	printf("%*.2sFIN\n", 4, "hola");	// . coge los 2 primeros char y añade (width - len(char *)) espacios a izq
	printf("%*sFIN\n", 6, "hola");			// añade (width - len(char *)) espacios a la izq
	printf("%-.2sFIN\n", "hola");
	printf("%0.2sFIN\n", "hola");
		// Estos ejemplos de flags no influyen en la cadena
	printf("X%-sFIN\n", "hola");
	printf("X%0sFIN\n", "hola");
	printf("X%-0sFIN\n", "hola"); // no mirar el printf no funcions con -0
	printf("X%0.7sFIN\n", "hola");
	printf("X%-.7sFIN\n", "hola");
	*/