/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:55:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/06 15:21:38 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fstring_init(t_fstring *f)
{
	f->head = 0;
	f->sign = 0;
	f->alt = NULL;
	f->pre_i = 0;
	f->pre = 0;
	f->partial = NULL;
	f->fw = 0;
}

void	ft_fstring_free(t_fstring *f)
{
	if (f->alt)
		free(f->alt);
	if (f->partial)
		free(f->partial);
}
