/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_add_nc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:21:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 18:27:30 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"
#include "ft_string.h"

size_t	ft_dstr_add_nc(t_dstring *s, char c, size_t len)
{
	size_t	i;

	i = 0;
	if (s->cap < s->pos + len + 1)
		ft_dstr_resize(s, s->cap * 2 + (s->cap >= len + 1 ? 0 : len + 1));
	while (i < len)
		s->buf[s->pos + i++] = c;
	s->buf[s->pos + len] = '\0';
	s->pos += len;
	return (len);
}
