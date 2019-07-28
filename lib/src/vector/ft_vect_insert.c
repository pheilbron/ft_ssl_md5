/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:57:07 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:47:17 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"

size_t	ft_vect_insert(t_vector *v, size_t pos, char *new_data, size_t len)
{
	if (v->size < v->pos + len)
		ft_vect_extend(v, len);
	ft_memmove(v->data + pos + len, v->data + pos, v->pos - pos);
	ft_memcpy(v->data + pos, new_data, len);
	v->pos += len;
	return (len);
}
