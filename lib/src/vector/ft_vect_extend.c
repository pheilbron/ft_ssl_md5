/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_extend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:02:25 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:46:54 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

size_t	ft_vect_extend(t_vector *v, size_t len)
{
	t_vector	*temp;

	temp = ft_vect_new(v->data, v->pos, v->size);
	ft_vect_del(v);
	v = ft_vect_new(temp->data, temp->pos,
			(temp->size > len ? temp->size * 2 : (temp->size * 2) + len));
	ft_vect_del(temp);
	return (v->size);
}
