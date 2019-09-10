/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_written.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:04:36 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 18:06:25 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_chars_written(t_dstring *s, t_form form, va_list *ap)
{
	int	*chars_written;

	form.lmod = 0;
	chars_written = va_arg(*ap, int *);
	*chars_written = s->pos;
	return (0);
}
