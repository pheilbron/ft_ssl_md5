/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_message_digest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:06:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 17:06:24 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_message_digest.h"

uint32_t	rotate_l(uint32_t x, uint8_t shift)
{
	return ((x << shift) | (x >> (32 - shift)));
}

uint32_t	rotate_r(uint32_t x, uint8_t shift)
{
	return ((x >> shift) | (x << (32 - shift)));
}

void		set_4b_file_hash(uint32_t *hash, uint32_t **file_hash, uint8_t len)
{
	uint8_t	i;

	i = 0;
	while (i < len)
	{
		(*file_hash)[i] = hash[i];
		i++;
	}
}
