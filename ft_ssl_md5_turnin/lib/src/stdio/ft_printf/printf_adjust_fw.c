/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_adjust_fw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:39:22 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/05 19:56:22 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_dstring.h"

int		ft_printf_adjust_fw(t_dstring *s, t_fstring f, t_form form)
{
	if (form.flags & _LEFT_JUST)
		return (ft_dstr_add_nc(s, ' ', f.fw));
	else if (form.flags & _ZERO)
	{
		if (f.pre_i > 0)
			return (ft_dstr_insert_nc(s, '0', f.fw, f.pre_i));
		else
			return (ft_dstr_insert_nc(s, '0', f.fw, f.head));
	}
	return (ft_dstr_insert_nc(s, ' ', f.fw, f.head));
}
