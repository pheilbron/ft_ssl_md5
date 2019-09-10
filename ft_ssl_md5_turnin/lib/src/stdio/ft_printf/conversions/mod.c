/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:51:03 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 09:13:50 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"

int	set_mod_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;
	va_list		empty;

	ft_fstring_init(&f);
	f.pre_i = s->pos;
	f.head = s->pos;
	va_copy(empty, *ap);
	len = ft_dstr_add(s, "%", 1);
	if ((f.fw = form.fw - len) > 0)
		len += ft_printf_adjust_fw(s, f, form);
	ft_fstring_free(&f);
	return (len);
}
