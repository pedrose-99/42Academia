#include "ft_printf.h"

void	caseh_zero_o_prec(unsigned int i, char *p, int tam_num, t_list *f)
{
	if (f->precision > 0)
		print_zero(f->precision - tam_num, f);
	else
		print_zero(f->width - tam_num, f);
	print_cosita(p, f);
}

char	*type_p(char *def)
{
	int	p;
	
	p = 0;
	def[p] = '0';
	p++;
	def[p] = 'x';
	p++;
	return (def);
}

char	 *trans_hexp(long long int i, char c)
{
	long long int		i_copy;
	char				*hex_char;
	char				*def;
	int					count;

	count = 3;
	hex_char = "0123456789abcdef";
	i_copy = trans_neg(i);
	while (i_copy >= 16 && (i_copy /= 16))
		count++;
	i_copy = trans_neg(i);
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
	def = type_p(def);
	return (def);
}

void	print_hexap(t_list *f)
{
	unsigned long long int	i;
	int						tam_num;
	char					*p;

	i = va_arg(f->ap, unsigned long long int);
	p = trans_hexp(i, f->spec);
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
			caseh_zero_o_prec(i, p, tam_num, f);
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
char *ptr; 
	ptr = ft_strdup("prueba puntero");

	ft_printf("%-pFIN\n", ptr);
	ft_printf("%0pFIN\n", ptr);
	ft_printf("%-0pFIN\n", ptr);
	ft_printf("%*pFIN\n", 20, ptr); // si
	ft_printf("%-*pFIN\n", 20, ptr); // si
	ft_printf("%0*pFIN\n", 20, ptr);
	ft_printf("%-0*pFIN\n", 20, ptr);
	ft_printf("%.3pFIN\n", ptr);
	ft_printf("%-.3pFIN\n", ptr);
	ft_printf("%0.3pFIN\n", ptr);
	ft_printf("%-0.3pFIN\n", ptr);
	// hasta aquí funciona incluso con undefined behavior
	ft_printf("%.17pFIN\n", ptr);
	ft_printf("%-.17pFIN\n", ptr);
	ft_printf("%0.17pFIN\n", ptr);
	ft_printf("%-0.17pFIN\n", ptr);
	ft_printf("%*.12pFIN\n", 20, ptr);
	ft_printf("%-*.3pFIN\n", 20, ptr);
	ft_printf("%0*.3pFIN\n", 20, ptr);
	ft_printf("%-0*.3pFIN\n", 20, ptr);
	// ARREGLAR ESTA PARTE (aunque no haría falta porque es undefined behavior)
	ft_printf("%*.17pFIN\n", 20, ptr);
	ft_printf("%-*.17pFIN\n", 20, ptr);
	ft_printf("%0*.17pFIN\n", 20, ptr);
	ft_printf("%-0*.17pFIN\n", 20, ptr);
		printf("hasta aqui\n");

	printf("hasta aqui \n");
	printf("%-pFIN\n", ptr);
	printf("%0pFIN\n", ptr);
	printf("%-0pFIN\n", ptr);
	printf("%*pFIN\n", 20, ptr); // si
	printf("%-*pFIN\n", 20, ptr); // si
	printf("%0*pFIN\n", 20, ptr);
	printf("%-0*pFIN\n", 20, ptr);
	printf("%.3pFIN\n", ptr);
	printf("%-.3pFIN\n", ptr);
	printf("%0.3pFIN\n", ptr);
	printf("%-0.3pFIN\n", ptr);
	// hasta aquí funciona incluso con undefined behavior
	printf("%.17pFIN\n", ptr);
	printf("%-.17pFIN\n", ptr);
	printf("%0.17pFIN\n", ptr);
	printf("%-0.17pFIN\n", ptr);
	ft_printf("%*.12pFIN\n", 20, ptr);
	ft_printf("%-*.3pFIN\n", 20, ptr);
	ft_printf("%0*.3pFIN\n", 20, ptr);
	ft_printf("%-0*.3pFIN\n", 20, ptr);
	// ARREGLAR ESTA PARTE (aunque no haría falta porque es undefined behavior)
	ft_printf("%*.17pFIN\n", 20, ptr);
	ft_printf("%-*.17pFIN\n", 20, ptr);
	ft_printf("%0*.17pFIN\n", 20, ptr);
	ft_printf("%-0*.17pFIN\n", 20, ptr);
	*/