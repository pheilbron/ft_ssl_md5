/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:07:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 09:10:40 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_math.h"

void	ft_printf_ldtoa(long double n, t_fstring *f, t_form form)
{
	long double	decimal;
	int			i;
	int			rounding;

	decimal = (n < 0 ? -n : n) - (long long)(n < 0 ? -n : n);
	i = -1;
	rounding = 0;
	if (!is_float_dne(n, f, form))
	{
		if ((f->alt = malloc(sizeof(*f->alt) * (form.pre + 1))))
		{
			while (++i < form.pre)
				f->alt[i] = (((int)(decimal * ft_llpow(10, i + 1))) % 10) + '0';
			f->alt[i] = '\0';
			if ((((int)(decimal * ft_llpow(10, i + 1))) % 10) >= 5)
				rounding = ft_printf_ldround(f, i - 1);
		}
		ft_printf_lltoa((long long)n + (n < 0 ? rounding * -1 : rounding), f);
		f->sign = (n + rounding < 0 ? '-' : f->sign);
	}
}

void	ft_printf_dtoa(double n, t_fstring *f, t_form form)
{
	double	decimal;
	int		i;
	int		rounding;

	decimal = (n < 0 ? -n : n) - (long long)(n < 0 ? -n : n);
	i = -1;
	rounding = 0;
	if (!is_float_dne(n, f, form))
	{
		if ((f->alt = malloc(sizeof(*f->alt) * (form.pre + 1))))
		{
			while (++i < form.pre)
				f->alt[i] = (((int)(decimal * ft_llpow(10, i + 1))) % 10) + '0';
			f->alt[i] = '\0';
			if ((((int)(decimal * ft_llpow(10, i + 1))) % 10) >= 5)
				rounding = ft_printf_ldround(f, i - 1);
		}
		ft_printf_lltoa((long long)n + (n < 0 ? rounding * -1 : rounding), f);
		f->sign = (n < 0 ? '-' : f->sign);
	}
}

int		set_float_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	ft_fstring_init(&f);
	if (form.lmod == ('l' + 'l'))
		ft_printf_ldtoa(va_arg(*ap, long double), &f, form);
	else
		ft_printf_dtoa(va_arg(*ap, double), &f, form);
	len = 0;
	f.head = s->pos;
	if (f.sign == '-' || (form.flags & _SIGN) || (form.flags & _BLANK))
		f.pre_i = f.head + (len +=
				ft_dstr_add(s, (f.sign == '-' || form.flags & _SIGN ?
						&(f.sign) : " "), 1));
	len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	if ((form.flags & _ALT) || (f.alt && *f.alt))
		len += ft_dstr_add(s, ".", 1);
	if (f.alt && *f.alt)
		len += ft_dstr_add(s, f.alt, ft_strlen(f.alt));
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
