/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:57:29 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 14:18:04 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dstring.h"
#include "ft_string.h"

t_dstring	*ft_dstr_resize(t_dstring *s, size_t len)
{
	char	*data;

	if (!(data = malloc(sizeof(*data) * len)))
		return (NULL);
	ft_memcpy(data, s->buf, s->pos);
	free(s->buf);
	s->buf = data;
	s->cap = len;
	return (s);
}
