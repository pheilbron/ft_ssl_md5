/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ldtoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:21:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 09:17:38 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

int		is_float_dne(long double n, t_fstring *f, t_form form)
{
	if (n != NAN && n != INF && n != NEG_INF)
		return (0);
	if (n == NAN)
		f->partial = ft_strdup((form.flags | _CAP ? "NAN" : "nan"));
	else if (n == NEG_INF)
		f->partial = ft_strdup((form.flags | _CAP) ? "-INF" : "-inf");
	else if (n == INF)
		f->partial = ft_strdup((form.flags | _CAP) ? "INF" : "inf");
	f->pre = -1;
	return (1);
}

int		ft_printf_ldround(t_fstring *f, int i)
{
	(f->alt[i])++;
	while (i >= 0 && f->alt[i] == '9' + 1)
	{
		f->alt[i] = '0';
		i--;
		(f->alt[i])++;
	}
	if (i < 0)
		return (1);
	return (0);
}
