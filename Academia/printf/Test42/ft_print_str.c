/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:22:31 by pserrano          #+#    #+#             */
/*   Updated: 2020/10/23 19:46:07 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	casestr_minus_precs(char *i, int tam_str, t_list *f)
{
	int tam_def;

	if (tam_str <= f->precision || f->precision < 0)
		tam_def = tam_str;
	else
		tam_def = f->precision;
	print_string(i, tam_def, f);
	print_space(f->width - tam_def, f);
}

void	casestr_zero_precs(char *i, int tam_str, t_list *f)
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

void	casestr_zero_o_width(char *i, int tam_str, t_list *f)
{
	if (f->zero > 0)
		print_zero(f->width - tam_str, f);
	else	
		print_space(f->width - tam_str, f);
	print_cosita(i, f);
}

void	casestr_minus(char *i, int tam_str, t_list *f)
{
	print_cosita(i, f);
	print_space((f->width - tam_str), f);
}

void	casestr_precision(char *i, int tam_str, t_list *f)
{
	if (tam_str < f->precision)
		print_string(i, tam_str, f);
	else
		print_string(i, f->precision, f);
}

void	print_str(t_list *f)
{
	char	*i;
	int		tam_str;

	i = va_arg(f->ap, char*);
	i = handle_string(i);
	tam_str = ft_strlen(i);
	if ((f->zero > 0 && f->precision < 0)
		|| (f->width > 0 && f->precision < 0 && f->minus < 0))
		casestr_zero_o_width(i, tam_str, f);
	else if (f->precision == 0)
		print_space(f->width, f);
	else if (f->minus > 0 && f->precision < 0)
		casestr_minus(i, tam_str, f);
	else if ((f->zero > 0 && f->precision > 0)
		|| (f->width > 0 && f->precision > 0 && f->minus < 0))
		casestr_zero_precs(i, tam_str, f);
	else if (f->minus > 0 && f->precision > 0)
		casestr_minus_precs(i, tam_str, f);
	else if (f->minus < 0 && f->width < 0 && f->precision < 0)
		print_cosita(i, f);
	else if (f->minus < 0 && f->width < 0 && f->precision > 0)
		casestr_precision(i, tam_str, f);
	free (i);
}
