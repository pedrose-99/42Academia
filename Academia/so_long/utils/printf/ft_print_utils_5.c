/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:13:57 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 10:26:54 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *i, int tam_str, t_list *f)
{
	int	p;

	p = 0;
	while (p < tam_str)
	{
		ft_putchar(i[p], f);
		p++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	casestr_minus_precs(char *i, int tam_str, t_list *f)
{
	int	tam_def;

	if (tam_str <= f->precision || f->precision < 0)
		tam_def = tam_str;
	else
		tam_def = f->precision;
	print_string(i, tam_def, f);
	print_space(f->width - tam_def, f);
}

void	casestr_zero_precs(char *i, int tam_str, t_list *f)
{
	int	tam_def;

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
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!(s2))
		return (0);
	while (s1[j])
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return ((char *)s2);
}
