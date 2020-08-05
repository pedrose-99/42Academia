#include "ft_printf.h"

void init_struct(t_list *f)
{
	f->cont = 0;
	f->spec = -1;
	f->minus = -1;
	f->argum = -1;
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
		{
			f->minus = 1;
		}
		else if (ft_is_num(*cosa))
		{
			f->width = ft_atoi(cosa);
			while (ft_is_num(*(cosa + 1)))
				cosa++;
		}
		else if (*cosa == '*')
		{
			f->width = va_arg(f->ap, int);
			f->argum = 1;
		}
		else if (*(cosa++) == '.')
		{
			if (*cosa == '*')
				f->precision = va_arg(f->ap, int);
			else
				f->precision = ft_atoi(cosa);
			if (!is_specifier(*cosa))
			{
				while (!is_specifier(*(cosa + 1)))
					cosa++;
			}
		}
		if (!is_specifier(*cosa))
		cosa++;
	}
	return (cosa);
}

void	ft_store_data_def(t_list *f)
{
	if (f->width < 0 && f->argum > 0)
	{
		f->minus = 1;
		f->width = f->width * (-1);
	}
	if (f->minus > 0)
		f->zero = -1;
}

void	print_char(t_list *f)
{
	char	i;

	i = va_arg(f->ap, int);
	if (i == '\0')
	{
		print_space(f->width -1 ,f);
		ft_putchar('\0', f);
	}
	else if ((f->zero > 0 && f->precision < 0) || (f->width > 0 && f->precision < 0 && f->minus < 0))
	{
		print_space(f->width - 1, f);
		print_cosita(&i, f);
	}
	else if (f->minus > 0)
	{
		print_cosita(&i, f);
		print_space((f->width - 1), f);
	}
}

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

char	*print_hexap_prec(char *p, t_list *f)
{
	int i;

	i = 0;
	while (i < 2)
	{
		ft_putchar(*p, f);
		p++;
		i++;
	}
	return (p);
}
void	caseh_width_prec(char *p, int i, int tam_num, t_list *f)
{
	if (i < 0)
		print_space(f->width - f->precision - 1, f);
	else
	{
		if(f->precision > tam_num) 
			print_space(f->width - f->precision, f);
		else
			print_space(f->width - tam_num, f);
	}
	tam_num = tam_num -2;
	p = print_hexap_prec(p, f);
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
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_cosita(p, f);
}

void	caseh_zero_o_prec(char *p, int tam_num, t_list *f)
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

char	 *trans_hexp(long long int i)
{
	long long int		i_copy;
	char				*hex_char;
	char				*def;
	int					count;

	count = 3;
	hex_char = "0123456789abcdef";
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
	def = type_p(def);
	return (def);
}

void	print_hexap(t_list *f)
{
	unsigned long long int	i;
	int						tam_num;
	char					*p;

	i = va_arg(f->ap, unsigned long long int);
	p = trans_hexp(i);
	tam_num = ft_strlen(p);
	if (i == 0)
		print_cosita("(nil)", f);
	else if ((f->zero > 0) && (f->precision > 0))
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
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_cosita(p, f);
}

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
void	minus_precs(int tam_str, char *i, t_list *f)
{
	int tam_def;

	if (tam_str <= f->precision || f->precision < 0)
		tam_def = tam_str;
	else if (!(ft_strncmp(i, "(null)", 6)))
		tam_def = 0;
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
	else if (!(ft_strncmp(i, "(null)", 6)))
		tam_def = 0;
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
		else if ((ft_strncmp(i, "(null)", 6)))
			print_string(i,f->precision, f);
	}
}

void	caseu_zero_o_prec(char *p, int tam_num, t_list *f)
{
	if (f->precision > 0)
	{
		print_zero(f->precision - tam_num, f);
	}
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
		print_space(f->width - f->precision , f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	caseu_minus_prec(char *p, int i, int tam_num, t_list *f)
{
	p = print_menos(i, p, f);
	if (i < 0)
	{
		if (f->precision > tam_num)
			tam_num--;
	}
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
	if (i < 0 && f->precision > tam_num)
		print_space(f->width - f->precision - 1, f);
	else if (i >= 0 && f->precision > tam_num)
		print_space(f->width - f->precision, f);
	else if (f->precision < tam_num)
		print_space((f->width - tam_num), f);
}

void	caseu_width_prec(int i, int tam_num, char *p, t_list *f)
{
	if (i < 0)
	{
		if (f->precision > tam_num)
			print_space(f->width - f->precision - 1, f);
		else
			print_space(f->width - tam_num, f);
	}
	else
		if (tam_num > f->precision)
			print_space(f->width - tam_num ,f);
		else
			print_space(f->width - f->precision, f);
	p = print_menos(i, p, f);
	if (i < 0)
		tam_num--;
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	print_unsigned(t_list *f)
{
	long long int				i;
	int						tam_num;
	char					*p;

	i = va_arg(f->ap, unsigned long int);
	if (i == -1)
		p = ft_itoa(4294967295);
	else
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
			caseu_zero_o_prec(p, tam_num, f);
	else if ((f->minus < 0) && f->width > 0 && f->precision <= 0)
	{
		print_space((f->width - tam_num), f);
		print_cosita(p, f);
	}
	else if (f->minus > 0 && f->precision > 0)
		caseu_minus_prec(p, i, tam_num, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		caseu_width_prec(i, tam_num, p, f);
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_cosita(p, f);
}

int	ft_strlen(char *str)
{
	int size;

	size = 0;
	if (!str)
		return (0);
	while (str[size])
		size++;
	return (size);
}

int		ft_count_nb(long int nb)
{
	long int		count;
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
void	case_zero_o_prec(int i, char *p, int tam_num, t_list *f)
{
	p = print_menos(i, p, f);
	if (f->precision > 0)
	{
		if (i < 0)
			tam_num--;
		print_zero(f->precision - tam_num, f);
	}
	else
		print_zero(f->width - tam_num, f);
	print_cosita(p, f);
}

void	case_zero_prec(int i, int tam_num, char *p, t_list *f)
{
	if (f->precision < tam_num)
	{
		print_space(f->width - tam_num, f);
		if (f->precision > tam_num)
			tam_num--;
	}
	else if (i < 0)
		print_space(f->width - f->precision - 1, f);
	else
		print_space(f->width - f->precision , f);
	if (i < 0)
	{
		p =	print_menos(i, p, f);
		tam_num = tam_num - 1;
	}
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	case_minus_prec(int i, int tam_num, char *p, t_list *f)
{
	p = print_menos(i, p, f);
	if (i < 0)
	{
		if (f->precision > tam_num)
			tam_num--;
	}
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
	if (i < 0 && f->precision > tam_num)
		print_space(f->width - f->precision - 1, f);
	else if (i >= 0 && f->precision > tam_num)
		print_space(f->width - f->precision, f);
	else if (f->precision < tam_num)
		print_space((f->width - tam_num), f);
}

void	case_width_prec(int i, int tam_num, char*p, t_list *f)
{
	if (i < 0)
	{
		if (f->precision > tam_num)
			print_space(f->width - f->precision - 1, f);
		else
			print_space(f->width - tam_num, f);
	}
	else
		if (tam_num > f->precision)
			print_space(f->width - tam_num ,f);
		else
			print_space(f->width - f->precision, f);
	p = print_menos(i, p, f);
	if (i < 0)
		tam_num--;
	print_zero(f->precision - tam_num, f);
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
	if ((f->zero > 0) && (f->precision > 0))
		case_zero_prec(i, tam_num, p, f);
	else if (f->minus > 0 && f->precision <= 0)
	{
		if (f->precision == 0 && i == 0)
			print_space(f->width, f);
		else
		{
			print_cosita(p, f);
			print_space((f->width - tam_num), f);
		}
	}
	else if ((f->zero > 0 && f->precision < 0)
		|| (f->zero < 0 && f->precision > 0 && f->minus < 0 && f->width < 0))
			case_zero_o_prec(i, p, tam_num, f);
	else if (f->minus < 0 && f->width > 0 && f->precision <= 0)
	{
		if (f->precision == 0 && i == 0)
			print_space(f->width, f);
		else
		{
			print_space((f->width - tam_num), f);
			print_cosita(p, f);
		}
	}
	else if (f->minus > 0 && f->precision > 0)
		case_minus_prec(i, tam_num, p, f);
	else if (f->minus < 0 && f->width > 0 && f->precision > 0)
		case_width_prec(i, tam_num, p, f);
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_cosita(p, f);

}
void	ft_putchar(char c, t_list *f)
{
	write(1, &c, 1);
	f->cont++;
}

char	*print_menos(int num, char *p, t_list *f)
{
	if (num < 0)
	{
		ft_putchar('-', f);
		p++;
	}
	return (p);
}

void	print_zero(int	tam, t_list *f)
{
	int i;

	i = 0;
	while (i < tam)
	{
		ft_putchar('0', f);
		i++;
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
	}
}
void	print_cosita(char *p, t_list *f)
{
	while (*p)
	{
		ft_putchar(*p, f);
		p++;
	}
}

void	ft_putnum(char *s, long int n, long int l)
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

char	*ft_itoa(long int n)
{
	char	*new;
	long int	l;

	if (n < -2147483648)
		return (NULL);
	l = ft_count_nb(n);
	new = (char*)malloc(sizeof(char) * l + 1);
	if (new == 0)
		return (NULL);
	ft_putnum(new, n, l);
	return (new);
}

int	ft_is_space(char str)
{
	return (str == '\t' || str == '\v' || str == '\f' || str == '\r' ||
			str == '\n' || str == ' ') ? (1) : (0);
}

int		ft_is_num(char str)
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

int ft_printf(const char *cosa, ...)
{
	t_list f;

	init_struct(&f);
	va_start(f.ap, cosa);
	while (*cosa)
	{
		if (*cosa == '%')
		{
			cosa = ft_store_data((char*)(cosa + 1), &f);
			ft_store_data_def(&f);
			f.spec = *(cosa++);
			print_todos(&f);
		
		}
		else
		{
			ft_putchar(*cosa, &f);
			cosa++;
		}
	}
	return (f.cont);
}
int		main(void)
{
//	printf("%i\n",ft_printf("this %s is empty\n", ""));
	static char *s_hidden = "hi low\0don't print me lol\0";
//	printf("%i\n",printf("this %s is empty\n", ""));
	long int INT_MAX;

	INT_MAX = 2147483648;
//	printf("%i\n",ft_printf("%*d\n", -10, 4));

//	printf("%i\n",printf("%*d\n", -10, 4));
	
	printf("%i\n",ft_printf("%5c", '\0'));
//	ft_printf("%d", 2);
//	ft_printf("%.s", "hello");
	//printf("%i\n",printf("%.0s", "hello"));
	printf("%i\n",printf("%5c", '\0'));
//		printf("%i\n",printf("%06d", -3));
}
// FIN\n;

