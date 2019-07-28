/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:59:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:47:41 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_stdlib.h"
#include "ft_string.h"

t_vector	*ft_vect_new(char *data, size_t len, size_t size)
{
	t_vector	*v;

	if (!(v = malloc(sizeof(*v))))
		return (NULL);
	if (!(v->data = ft_memalloc(sizeof(*data) * size)))
		return (NULL);
	ft_memcpy(v->data, data, len);
	v->size = size;
	v->pos = len;
	return (v);
}
