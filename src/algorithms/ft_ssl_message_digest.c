/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_message_digest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:06:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 19:27:35 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_message_digest.h"

uint64_t	rot_l(uint64_t x, uint8_t shift, uint8_t data_size)
{
	if (shift < data_size)
		return ((x << shift) | (x >> (data_size - shift)));
	return (x);
}

uint64_t	rot_r(uint64_t x, uint8_t shift, uint8_t data_size)
{
	if (shift < data_size)
		return ((x >> shift) | (x << (32 - shift)));
	return (x);
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
