/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:29:18 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 21:12:20 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <inttypes.h>
# include <limits.h>

# include "ft_dstring.h"

# define _ALT 1
# define _ZERO 2
# define _LEFT_JUST 4
# define _BLANK 8
# define _SIGN 16
# define _CAP 32

# define NAN (0.0 / 0)
# define INF (1.0 / 0)
# define NEG_INF (-1.0 / 0)

typedef struct	s_form
{
	uint8_t			flags;
	int				fw;
	int				pre;
	unsigned char	lmod;
	char			type;
}				t_form;

typedef struct	s_fstring
{
	int		head;
	char	sign;
	char	*alt;
	int		pre_i;
	int		pre;
	char	*partial;
	int		fw;
}				t_fstring;

typedef struct	s_con
{
	char		type;
	int			(*f)(t_dstring *, t_form, va_list *);
}				t_con;

typedef struct	s_color
{
	char		*type;
	char		*escape_code;
}				t_color;

int				ft_printf(const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);

int				is_data_lmod(char c);
int				is_data_conversion(char c);
int				is_data_flag(char c);
int				is_con_indicator(char c);
int				is_float_dne(long double n, t_fstring *f, t_form form);

int				ft_printf_ldround(t_fstring *f, int i);

void			set_data_flags(const char **s, int *pos, t_form *form);
void			set_data_fw(const char **s, int *pos, t_form *form,
		va_list *ap);
void			set_data_precision(const char **s, int *pos, t_form *form,
		va_list *ap);
void			set_data_lmod(const char **s, int *pos, t_form *form);
void			ft_form_clean(t_form *f);

int				ft_printf_adjust_fw(t_dstring *s, t_fstring f, t_form form);

void			ft_printf_lltoa(long long n, t_fstring *f);

void			get_unsigned_con(t_form form, unsigned long long value,
		t_fstring *f);

void			ft_fstring_init(t_fstring *f);
void			ft_fstring_free(t_fstring *f);

int				(*g_convert_data(char type))(t_dstring *, t_form, va_list *);
void			(*g_convert(char *format, int i))
	(t_dstring *, const char **, int *, va_list *);

int				set_char_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_int_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_float_fstring(t_dstring *s, t_form form, va_list *ap);
int				get_chars_written(t_dstring *s, t_form form, va_list *ap);
int				set_pointer_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_non_print_fstring(t_dstring *s,
		t_form form, va_list *ap);
int				set_string_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_unsigned_fstring(t_dstring *s,
		t_form form, va_list *ap);
int				set_mod_fstring(t_dstring *s, t_form form, va_list *ap);
int				set_color_fstring(t_dstring *s,
		const char **f_string, int *pos);

#endif
