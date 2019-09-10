/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 07:58:02 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 14:15:39 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"
#include "ft_string.h"

size_t	ft_dstr_add(t_dstring *s, char *new_data, size_t len)
{
	if (s->cap < s->pos + len + 1)
		ft_dstr_resize(s, s->cap * 2 + (s->cap >= len + 1 ? 0 : len + 1));
	ft_memcpy(s->buf + s->pos, new_data, len);
	s->buf[s->pos + len] = '\0';
	s->pos += len;
	return (len);
}
