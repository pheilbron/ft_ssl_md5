/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_insert_nc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:33:17 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 13:45:36 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"
#include "ft_string.h"

size_t	ft_dstr_insert_nc(t_dstring *s, char c, size_t len, size_t pos)
{
	size_t	i;

	i = 0;
	if (s->cap < s->pos + len + 1)
		ft_dstr_resize(s, s->cap * 2 + (s->cap >= len + 1 ? 0 : len + 1));
	if (pos <= s->pos)
	{
		ft_memmove(s->buf + pos + len, s->buf + pos, s->pos - pos);
		while (i < len)
			s->buf[pos + i++] = c;
		s->buf[s->pos + len] = '\0';
		s->pos += len;
		return (len);
	}
	return (0);
}
