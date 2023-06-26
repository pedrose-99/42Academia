/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:54:27 by pserrano          #+#    #+#             */
/*   Updated: 2023/06/22 10:27:09 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	va_list		ap;
	int			cont;
	char		spec;
	int			argum;
	int			zero;
	int			minus;
	int			width;
	int			precision;
}				t_list;
/*
**		ft_store.c
*/
void			init_struct(t_list *f);
int				is_specifier(char c);
char			*ft_case_point(char *format_string, t_list *f);
char			*ft_store_data(char *format_string, t_list *f);
void			ft_store_data_def(t_list *f);
/*
**		ft_print_char.c
*/
void			print_char(t_list *f);
void			casec_zero_or_width(char i, t_list *f);
void			caseint_zero_o_prec(int i, char *p, int tam_num, t_list *f);
void			caseint_zero_prec(int i, int tam_num, char *p, t_list *f);
/*
**		ft_print_str.c
*/
char			*handle_string(char *s);
void			casestr_zero_o_width(char *i, int tam_str, t_list *f);
void			casestr_minus(char *i, int tam_str, t_list *f);
void			casestr_precision(char *i, int tam_str, t_list *f);
void			print_str(t_list *f);
/*
**		ft_printf.c
*/
int				ft_strlen(char *str);
int				ft_count_nb(long int nb);
void			print_all(t_list *f);
int				ft_printf(const char *format_string, ...);
/*
**		ft_printf_int.c
*/
void			caseint_minus_prec(int i, int tam_num, char *p, t_list *f);
void			caseint_width_prec(int i, int tam_num, char *p, t_list *f);
void			caseint_minus(int i, int tam_num, char *p, t_list *f);
void			caseint_width(int i, int tam_num, char *p, t_list *f);
void			print_int(t_list *f);
/*
**		ft_print_utils.c
*/
void			ft_putchar(char c, t_list *f);
char			*print_menos(int num, char *p, t_list *f);
void			print_zero(int tam, t_list *f);
void			print_space(int tam, t_list *f);
void			print_conversion_str(char *p, t_list *f);
/*
**		ft_print_utils_2.c
*/
void			caseh_minus(char *p, int i, int tam_num, t_list *f);
void			caseu_zero_o_prec(char *p, int tam_num, t_list *f);
void			caseu_zero_prec(char *p, int tam_num, t_list *f);
/*
**		ft_print_utils_3.c
*/
void			ft_putnum(char *s, long int n, long int l);
char			*ft_itoa(long int n);
int				ft_is_space(char str);
int				ft_is_num(char str);
int				ft_atoi(const char *str);
/*
**		ft_print_utils_4.c
*/
void			casehp_minus(char *p, int tam_num, t_list *f);
void			casehp_width(char *p, int tam_num, t_list *f);
void			caseh_zero_o_prec(char *p, int tam_num, t_list *f);
char			*type_p(char *def);
char			*print_hexap_prec(char *p, t_list *f);
/*
**		ft_print_utils_5.c
*/
void			print_string(char *i, int tam_str, t_list *f);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			casestr_minus_precs(char *i, int tam_str, t_list *f);
void			casestr_zero_precs(char *i, int tam_str, t_list *f);
char			*ft_strdup(char *s1);
#endif
