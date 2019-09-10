/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:05:40 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 16:08:50 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_dstring.h"

int	set_pointer_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	ft_fstring_init(&f);
	form.type = 'x';
	form.flags |= _ALT;
	get_unsigned_con(form, (unsigned long long)va_arg(*ap, void *), &f);
	f.pre = form.pre - ft_strlen(f.partial);
	len = 0;
	f.head = s->pos;
	f.pre_i = f.head + (len += ft_dstr_add(s, f.alt, ft_strlen(f.alt)));
	if (form.pre == -1 || ft_strcmp(f.partial, "0") != 0)
	{
		if (f.pre > 0)
			len += ft_dstr_add_nc(s, '0', f.pre);
		len += ft_dstr_add(s, f.partial, ft_strlen(f.partial));
	}
	else
		len += ft_dstr_add_nc(s, '0', (form.pre > 0 ? form.pre : 0));
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
