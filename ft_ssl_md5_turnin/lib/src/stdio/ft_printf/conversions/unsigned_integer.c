/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:08:46 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 18:47:02 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"
#include "ft_string.h"
#include "ft_math.h"

void		ft_printf_ulltoa_base(unsigned long long n, int base, int cap,
		t_fstring *f)
{
	int		digit;
	int		i;
	char	*values;
	char	*c_values;

	digit = 0;
	i = 0;
	values = "0123456789abcdef";
	c_values = "0123456789ABCDEF";
	while (n / ft_ullpow(base, digit) >= (unsigned int)base)
		digit++;
	if ((f->partial = (char *)malloc(sizeof(*(f->partial)) * (digit + 2))))
	{
		while (digit >= 0)
		{
			if (cap)
				f->partial[i++] = c_values[n / ft_ullpow(base, digit)];
			else
				f->partial[i++] = values[n / ft_ullpow(base, digit)];
			n -= (n / ft_ullpow(base, digit)) * ft_ullpow(base, digit);
			digit--;
		}
		f->partial[i] = '\0';
	}
}

void		get_unsigned_con(t_form form, unsigned long long value,
		t_fstring *f)
{
	f->alt = NULL;
	if (form.type == 'b')
	{
		ft_printf_ulltoa_base(value, 2, form.flags & _CAP, f);
		if ((form.flags & _ALT) && (form.flags & _CAP))
			f->alt = ft_strdup("0B");
		else if (form.flags & _ALT)
			f->alt = ft_strdup("0b");
	}
	else if (form.type == 'o')
	{
		ft_printf_ulltoa_base(value, 8, form.flags & _CAP, f);
		if ((form.flags & _ALT) && (f->partial[0] != '0' || form.pre == 0))
			f->alt = ft_strdup("0");
	}
	else if (form.type == 'x')
	{
		ft_printf_ulltoa_base(value, 16, form.flags & _CAP, f);
		if ((form.flags & _ALT) && (form.flags & _CAP))
			f->alt = ft_strdup("0X");
		else if (form.flags & _ALT)
			f->alt = ft_strdup("0x");
	}
	else
		ft_printf_ulltoa_base(value, 10, form.flags & _CAP, f);
}

void		get_unsigned_partial(t_fstring *f, t_form form, va_list *ap)
{
	if (form.lmod == ('h' + 'h'))
		get_unsigned_con(form, (unsigned char)va_arg(*ap, unsigned int), f);
	else if (form.lmod == 'h')
		get_unsigned_con(form, (unsigned short)va_arg(*ap, unsigned int), f);
	else if (form.lmod == 'l')
		get_unsigned_con(form, va_arg(*ap, unsigned long), f);
	else if (form.lmod == ('l' + 'l'))
		get_unsigned_con(form, va_arg(*ap, unsigned long long), f);
	else if (form.lmod == 'j')
		get_unsigned_con(form, va_arg(*ap, uintmax_t), f);
	else if (form.lmod == 'z')
		get_unsigned_con(form, va_arg(*ap, size_t), f);
	else
		get_unsigned_con(form, va_arg(*ap, unsigned int), f);
}

int			set_unsigned_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	ft_fstring_init(&f);
	get_unsigned_partial(&f, form, ap);
	len = ft_strlen(f.partial);
	f.pre = form.pre - len;
	len = 0;
	f.head = s->pos;
	if ((form.flags & _ALT) && (ft_strcmp(f.partial, "0") != 0 ||
				(form.type == 'o' && form.pre == 0)))
	{
		f.pre_i = f.head + (len += ft_dstr_add(s, f.alt, ft_strlen(f.alt)));
		f.pre -= (form.type == 'o' ? 1 : 0);
	}
	if (f.pre > 0)
		len += ft_dstr_add_nc(s, '0', f.pre);
	if (!(form.pre == 0 && ft_strcmp(f.partial, "0") == 0))
		len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
