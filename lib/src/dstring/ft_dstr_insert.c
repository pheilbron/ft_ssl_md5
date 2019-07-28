/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 07:59:13 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:04:55 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"
#include "ft_string.h"

void	ft_dstr_insert(t_dstring *s, char *new_data, size_t len, size_t pos)
{
	if (s->cap < s->pos + len + 1)
		ft_dstr_extend(s, s->cap * 2 + (s->cap >= len ? 0 : len));
	ft_memmove(s->buf + pos + len, s->buf + pos, s->pos - pos);
	ft_memcpy(s->buf + pos, new_data, len);
	s->buf[s->pos + len] = '\0';
	s->pos += len;
}
