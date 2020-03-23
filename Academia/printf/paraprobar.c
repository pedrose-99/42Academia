#include "ft_printf.h"

char	*ft_strdup(const char *s1)
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

int	ft_strlen(char *str)
{
	int size;

	size = 0;
	while (*str)
	{
		str++;
		size++;
	}
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

void	ft_store_data_def(t_list *f)
{
	if (f->width < 0)
	{
		f->minus = 1;
		f->width = f->width * (-1);
	}
	if (f->minus > 0)
		f->zero = -1;
}

void	case_zero_o_prec(int i, int tam_num, char *p, t_list *f)
{
	p = print_menos(i, p, f);
	if (f->precision > 0)
		print_zero(f->precision - tam_num, f);
	else
		print_zero(f->width - tam_num, f);
	print_cosita(p, f);
}

void	case_zero_prec(int i, int tam_num, char *p, t_list *f)
{
	if (f->precision < tam_num)
		print_space(f->width - tam_num, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	case_minus_prec(int i, int tam_num, char *p, t_list *f)
{
	p = print_menos(i, p, f);
	if (i < 0)
		tam_num--;
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
	if (i < 0 && f->precision > tam_num)
		print_space(f->width - f->precision - 1, f);
	else if (i > 0 && f->precision > tam_num)
		print_space(f->width - f->precision, f);
	else if (f->precision < tam_num)
		print_space((f->width - tam_num), f);
}

void	case_width_prec(int i, int tam_num, char*p, t_list *f)
{
	if (i < 0)
		print_space(f->width - f->precision - 1, f);
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
	long int		i;
	int				tam_num;
	char			*p;

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
	unsigned long int	i;
	int				tam_num;
	char			*p;

	i = va_arg(f->ap, unsigned long int);
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
void	caseh_zero_o_prec(unsigned int i, char *p, int tam_num, t_list *f)
{
	if (f->precision > 0)
		print_zero(f->precision - tam_num, f);
	else
		print_zero(f->width - tam_num, f);
	print_cosita(p, f);
}
// no se si este esta bien, ya que deberia funcionar solo como si fuese precision.
void	caseh_zero_prec(char *p, int tam_num, t_list *f)
{
	if (f->precision < tam_num)
		print_space(f->width - tam_num, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

void	caseh_minus_prec(char *p, unsigned int i, int tam_num, t_list *f)
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
	if (i < 0)
		print_space(f->width - f->precision - 1, f);
	else
		print_space(f->width - f->precision, f);
	print_zero(f->precision - tam_num, f);
	print_cosita(p, f);
}

int		trans_neg(long int i)
{
	if (i < 0)
		i = 4294967295 + i + 1;
	return (i);
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
			ft_store_data_def(&f);
			f.spec = *(cosa++);
			print_hexap(&f);
		
		}
		else
		{
			ft_putchar(*cosa, &f);
			cosa++;
		}
	}
	return (1);
}

int		main(void)
{
	//printf("%0-6.3dg\n", 22);
	//print_spozero(22, 6, 6);
	ft_printf("%p", 20000);
	printf("%p", 20000);
}
