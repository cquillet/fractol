/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:45:20 by cquillet          #+#    #+#             */
/*   Updated: 2017/10/30 17:58:00 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>
# include <stdarg.h>
# include <wchar.h>
# include <stddef.h>
# include "libft.h"

# ifndef FT_PRINTF_PARAM
#  define FT_PRINTF_PARAM
#  define WIDTH_FIELD 1
#  define PRECISION_FIELD 0
#  define NO_LEN 0
#  define LEN_SSHORT 1
#  define LEN_SHORT 2
#  define LEN_LONG 3
#  define LEN_LLONG 4
#  define LEN_INTMAX 5
#  define LEN_SIZET 6
#  define LEN_PTRDIFF 7
#  define LEN_LDOUBLE 8
# endif

typedef struct	s_format
{
	int			sharp;
	int			left;
	char		pad;
	char		sign;
	int			force_period;
	int			base;
	char		prefix_conv;
	int			zero_not_removed;
	int			min_field;
	char		period;
	int			precision_defined;
	int			precision;
	char		length;
	char		type;
	char		*repr;
	char		*s_int;
	char		*s_float;
	int			l_int;
	int			round;
	ssize_t		nb_printed;
}				t_format;

/*
** c_char.c
*/

int				get_shortshort(va_list ap, t_format *f);
int				get_char(va_list ap, t_format *f);
int				get_percent(t_format *f);

/*
** c_double.c
*/

int				get_double(va_list ap, t_format *f);

/*
** c_int.c
*/

int				get_int(va_list ap, t_format *f);
int				get_ptrdiff_t(va_list ap, t_format *f);

/*
** c_intmax.c
*/

int				get_intmax(va_list ap, t_format *f);

/*
** c_long.c
*/

int				get_long(va_list ap, t_format *f);

/*
** c_longdouble.c
*/

int				get_longdouble(va_list ap, t_format *f);

/*
** c_longlong.c
*/

int				get_longlong(va_list ap, t_format *f);

/*
** c_pointers.c
*/

int				get_ptr(va_list ap, t_format *f);

/*
** c_short.c
*/

int				get_short(va_list ap, t_format *f);

/*
** c_size_t.c
*/

int				get_size_t(va_list ap, t_format *f);

/*
** c_str.c
*/

int				get_string(va_list ap, t_format *f);
int				get_wstring(va_list ap, t_format *f);

/*
** c_wchar.c
*/

int				get_wchar(va_list ap, t_format *f);
int				len_wchar(wint_t c);
int				wchar_to_char(char *dst, wint_t c);

/*
** characters.c
*/

int				display_char(va_list ap, t_format *f);

/*
** floats.c
*/

int				display_floats(va_list ap, t_format *f);
int				float_nb(long double nb, t_format *f);
int				complete_float_right(t_format *f);
int				complete_float_left(t_format *f);

/*
** format.c
*/

int				check_fields(t_format *f);
t_format		*init_format(t_format *f);
void			free_format(t_format *f);

/*
** integers.c int_display.c
*/

int				display_integers(va_list ap, t_format *f);
int				signed_nb(intmax_t n, t_format *f);
int				unsigned_nb(uintmax_t n, t_format *f);
int				complete_nb_right(t_format *f);
int				complete_nb_left(t_format *f);

/*
** main.c
*/

int				main(int ac, char **av);
int				rec_printf(int n);

/*
** pointers.c
*/

int				display_ptr(va_list ap, t_format *f);

/*
** printf.c
*/

int				readstr(char *s, t_format *f);
int				display_arg(va_list ap, t_format *f);
int				ft_printf(const char *fmt, ...);

/*
** read.c
*/

char			*read_format(char *s, t_format *f, va_list ap);

/*
** strings.c
*/

int				display_str(va_list ap, t_format *f);
int				complete_str_right(t_format *f);
int				complete_str_left(t_format *f);

/*
** type.c
*/

int				type_exists(char c);
int				type_is_char(char c);
int				type_is_str(char c);
int				type_is_ptr(char c);
int				type_includes_long(char c);

/*
** type_nb.c
*/

int				type_is_nb(char c);
int				type_is_int(char c);
int				type_is_float_dec(char c);
int				type_is_float(char c);

#endif
