/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:56:33 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:46:23 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"

size_t	ft_vect_add(t_vector *v, char *new_data, size_t len)
{
	if (v->size < v->pos + len)
		ft_vect_extend(v, len);
	ft_memcpy(v->data + v->pos, new_data, len);
	v->pos += len;
	return (len);
}
