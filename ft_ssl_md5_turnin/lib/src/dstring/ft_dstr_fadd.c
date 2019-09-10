/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_fadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:20:37 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 15:37:31 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"
#include "ft_string.h"

int	ft_dstr_addf(t_dstring *s, const char *format, ...)
{
	va_list		ap;
	int			i;
	int			start;

	va_start(ap, format);
	i = 0;
	start = s->pos;
	while (format[i])
	{
		if (is_con_indicator(format[i]))
		{
			ft_dstr_add(s, (char *)format, i);
			format += i;
			i = 0;
			(*g_convert((char *)format, i))(s, &format, &i, &ap);
		}
		else
			i++;
	}
	ft_dstr_add(s, (char *)format, i);
	va_end(ap);
	return (s->pos - start);
}
