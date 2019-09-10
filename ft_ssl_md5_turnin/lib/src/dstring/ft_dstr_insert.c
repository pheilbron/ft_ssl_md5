/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:27:48 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 13:44:43 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"
#include "ft_string.h"

size_t	ft_dstr_insert(t_dstring *s, char *new_data, size_t len, size_t pos)
{
	if (s->cap < s->pos + len + 1)
		ft_dstr_resize(s, s->cap * 2 + (s->cap >= len + 1 ? 0 : len + 1));
	if (pos <= s->pos)
	{
		ft_memmove(s->buf + pos + len, s->buf + pos, s->pos - pos);
		ft_memcpy(s->buf + pos, new_data, len);
		s->buf[s->pos + len] = '\0';
		s->pos += len;
		return (len);
	}
	return (0);
}
