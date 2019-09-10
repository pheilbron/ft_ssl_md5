/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_print_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:23:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 10:54:15 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"
#include "ft_string.h"
#include "ft_math.h"
#include "ft_ctype.h"

void	set_non_print_char(t_dstring *s, unsigned char c)
{
	int		digit;
	char	*values;

	digit = 0;
	values = "0123456789abcdef";
	ft_dstr_add(s, "\\x", 2);
	if (c < 16)
		ft_dstr_add(s, "0", 1);
	while (c / ft_pow(16, digit) >= 16)
		digit++;
	while (digit >= 0)
	{
		ft_dstr_add(s, values + (c / ft_pow(16, digit)), 1);
		c -= (c / ft_pow(16, digit)) * ft_pow(16, digit);
		digit--;
	}
}

char	*get_non_print_partial(char *s)
{
	t_dstring	*temp;
	int			len;
	int			i;

	len = ft_strlen(s);
	temp = ft_dstr_new("", 0, len);
	i = 0;
	while (i < len)
	{
		if (!ft_isprint(s[i]))
			set_non_print_char(temp, s[i]);
		else
			ft_dstr_add(temp, s + i, 1);
		i++;
	}
	return (ft_dstr_release(temp));
}

int		set_non_print_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	ft_fstring_init(&f);
	if (form.lmod == 'l')
		f.partial = get_non_print_partial((char *)va_arg(*ap, wchar_t *));
	else
		f.partial = get_non_print_partial(va_arg(*ap, char *));
	f.partial = (f.partial ? ft_strdup(f.partial) : ft_strdup("(null)"));
	f.head = s->pos;
	f.pre_i = s->pos;
	f.pre = (form.pre >= 0 && form.pre < (int)ft_strlen(f.partial) ?
			form.pre : ft_strlen(f.partial));
	len = ft_dstr_add(s, f.partial, f.pre);
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
