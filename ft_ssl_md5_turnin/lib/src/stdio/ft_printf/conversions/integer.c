/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:42:01 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 18:49:24 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_math.h"
#include "ft_dstring.h"

void		ft_printf_lltoa(long long n, t_fstring *f)
{
	int		digit;
	int		i;

	f->sign = (n >= 0 ? '+' : '-');
	if (n == LLONG_MIN)
		f->partial = ft_strdup("9223372036854775808");
	else
	{
		n *= (f->sign == '-' ? -1 : 1);
		digit = 0;
		i = 0;
		while (n / ft_llpow(10, digit) >= 10)
			digit++;
		if ((f->partial = (char *)malloc(sizeof(*(f->partial)) * (digit + 2))))
		{
			while (digit >= 0)
			{
				f->partial[i++] = (n / ft_llpow(10, digit)) + '0';
				n -= (n / ft_llpow(10, digit)) * ft_llpow(10, digit);
				digit--;
			}
			f->partial[i] = '\0';
		}
	}
}

void		get_int_partial(t_fstring *f, t_form form, va_list *ap)
{
	if (form.lmod == ('h' + 'h'))
		ft_printf_lltoa((signed char)va_arg(*ap, int), f);
	else if (form.lmod == 'h')
		ft_printf_lltoa((short)va_arg(*ap, int), f);
	else if (form.lmod == 'l')
		ft_printf_lltoa(va_arg(*ap, long), f);
	else if (form.lmod == ('l' + 'l'))
		ft_printf_lltoa(va_arg(*ap, long long), f);
	else if (form.lmod == 'j')
		ft_printf_lltoa(va_arg(*ap, intmax_t), f);
	else if (form.lmod == 'z')
		ft_printf_lltoa(va_arg(*ap, size_t), f);
	else
		ft_printf_lltoa(va_arg(*ap, int), f);
	f->alt = NULL;
}

int			set_int_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	ft_fstring_init(&f);
	get_int_partial(&f, form, ap);
	len = ft_strlen(f.partial);
	f.pre = form.pre - len;
	len = 0;
	f.head = s->pos;
	if (f.sign == '-' || (form.flags & _SIGN) || (form.flags & _BLANK))
		f.pre_i = f.head + (len +=
				ft_dstr_add(s, (f.sign == '-' || form.flags & _SIGN ?
						&(f.sign) : " "), 1));
	if (f.pre > 0)
		len += ft_dstr_add_nc(s, '0', f.pre);
	if (!(form.pre == 0 && ft_strcmp(f.partial, "0") == 0))
		len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
