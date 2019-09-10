/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_overwrite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:19:49 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 14:21:13 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"
#include "ft_string.h"

size_t	ft_dstr_overwrite(t_dstring *s, char *new_data, size_t len)
{
	if (s->cap < len + 1)
		ft_dstr_resize(s, s->cap * 2 + (s->cap >= len + 1 ? 0 : len + 1));
	ft_memcpy(s->buf, new_data, len);
	s->buf[len] = '\0';
	s->pos = len;
	return (len);
}
