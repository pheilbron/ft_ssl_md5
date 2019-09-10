/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:36:30 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 09:09:20 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"
#include "ft_string.h"

int	set_char_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	char		c;
	int			len;

	ft_fstring_init(&f);
	if (form.lmod == 'l')
		c = ((wchar_t)va_arg(*ap, int));
	else
		c = ((char)va_arg(*ap, int));
	f.pre_i = s->pos;
	f.head = s->pos;
	f.partial = &c;
	len = ft_dstr_add(s, f.partial, sizeof(*f.partial));
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	return (len);
}
