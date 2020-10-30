/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:54:27 by pserrano          #+#    #+#             */
/*   Updated: 2020/10/23 20:04:51 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct		s_list
{
	//char		*cosa; //para almacenar el string
	va_list		ap;

	int			cont; //contar el numero de "letras"

	char		spec; //el tipo de letra que sea(s, d, u)

	int			argum;
	int			zero; 
	int			minus; //'-'
	int			width; //ancho 0 10000
	int			precision; // para la precision
}					t_list;
//almacendatos.c
void	init_struct(t_list *f);
int		is_specifier(char c);
char	*ft_case_point(char *cosa, t_list *f);
char	*ft_store_data(char *cosa, t_list *f);
void	ft_store_data_def(t_list *f);
//ft_print_char.c
void	print_char(t_list *f);
//ft_print_hexa.c
char	*trans_hex(long int i, char c);
void	caseh_minus(char *p, int i, int tam_num, t_list *f);
void	caseh_width(char *p, int i, int tam_num, t_list *f);
void	caseh_zero_prec(char *p, int tam_num, t_list *f);
void	caseh_minus_prec(char *p, int i, int tam_num, t_list *f);
void	caseh_width_prec(char *p, int i, int tam_num, t_list *f);
void	print_hexa(t_list *f);
//ft_print_hexap.c
void	casehp_minus(char *p, int tam_num, t_list *f);
void	casehp_width(char *p, int tam_num, t_list *f);
void	caseh_zero_o_prec(char *p, int tam_num, t_list *f);
char	*type_p(char *def);
char	*print_hexap_prec(char *p, t_list *f);
void	casehp_width_prec(char *p, int i, int tam_num, t_list *f);
char	*trans_hexp(long long int i);
void	print_hexap(t_list *f);
char	*handle_hexa(char *s);
//ft_print_str.c
void	print_string(char *i, int tam_str, t_list *f);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	casestr_minus_precs(char *i, int tam_str, t_list *f);
void	casestr_zero_precs(char *i, int tam_str, t_list *f);
char	*ft_strdup(char *s1);
char	*handle_string(char *s);
void	casestr_zero_o_width(char *i, int tam_str, t_list *f);
void	casestr_minus(char *i, int tam_str, t_list *f);
void	casestr_precision(char *i, int tam_str, t_list *f);
void	print_str(t_list *f);
//ft_printf_unsigned.c
void	caseu_zero_o_prec(char *p, int tam_num, t_list *f);
void	caseu_zero_prec(char *p, int tam_num, t_list *f);
void	caseu_minus_prec(char *p, int i, int tam_num, t_list *f);
void	caseu_width_prec(int i, int tam_num, char *p, t_list *f);
void	caseu_minus(char *p, int tam_num, int i, t_list *f);
void	caseu_width(char *p, int tam_num, int i, t_list *f);
void	print_unsigned(t_list *f);
//ft_printf.c
int		ft_strlen(char *str);
int		ft_count_nb(long int nb);
void	print_todos(t_list *f);
int 		ft_printf(const char *cosa, ...);
//ft_printf_int.c
void	caseint_zero_o_prec(int i, char *p, int tam_num, t_list *f);
void	caseint_zero_prec(int i, int tam_num, char *p, t_list *f);
void	caseint_minus_prec(int i, int tam_num, char *p, t_list *f);
void	caseint_width_prec(int i, int tam_num, char *p, t_list *f);
void	caseint_minus(int i, int tam_num, char *p, t_list *f);
void	caseint_width(int i, int tam_num, char *p, t_list *f);
void	print_int(t_list *f);
//ft_print_utils.c
void	ft_putchar(char c, t_list *f);
char	*print_menos(int num, char *p, t_list *f);
void	print_zero(int tam, t_list *f);
void	print_space(int tam, t_list *f);
void	print_cosita(char *p, t_list *f);
//ft_funciones_extra.c
void	ft_putnum(char *s, long int n, long int l);
char	*ft_itoa(long int n);
int		ft_is_space(char str);
int		ft_is_num(char str);
int		ft_atoi(const char *str);
#endif