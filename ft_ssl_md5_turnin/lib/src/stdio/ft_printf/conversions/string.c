/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:40:33 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 14:11:04 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"
#include "ft_string.h"

int	set_string_fstring(t_dstring *s, t_form form, va_list *ap)
{
	t_fstring	f;
	int			len;

	ft_fstring_init(&f);
	if (form.lmod == 'l')
		f.partial = (char *)va_arg(*ap, wchar_t *);
	else
		f.partial = va_arg(*ap, char *);
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
