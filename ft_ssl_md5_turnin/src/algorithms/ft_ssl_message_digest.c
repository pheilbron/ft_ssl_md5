/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_message_digest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:06:19 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 11:06:04 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_message_digest.h"

#define BYTE_1_MASK (uint32_t)0xFF000000
#define BYTE_2_MASK (uint32_t)0xFF0000
#define BYTE_3_MASK (uint32_t)0xFF00
#define BYTE_4_MASK (uint32_t)0xFF

uint64_t	rot_l(uint64_t x, uint8_t shift, uint8_t data_size)
{
	if (shift < data_size)
		return ((x << shift) | (x >> (data_size - shift)));
	return (x);
}

uint64_t	rot_r(uint64_t x, uint8_t shift, uint8_t data_size)
{
	if (shift < data_size)
		return ((x >> shift) | (x << (data_size - shift)));
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

void		set_4b_le_file_hash(uint32_t *hash, uint32_t **file_hash,
		uint8_t len)
{
	uint8_t	i;

	i = 0;
	while (i < len)
	{
		(*file_hash)[i] = (((hash[i] & BYTE_1_MASK) >> 24) |
			((hash[i] & BYTE_2_MASK) >> 8) |
			((hash[i] & BYTE_3_MASK) << 8) |
			((hash[i] & BYTE_4_MASK) << 24));
		i++;
	}
}

void		set_8b_to_4b_file_hash(uint64_t *hash, uint32_t **file_hash,
		uint8_t len)
{
	uint8_t	i;

	i = 0;
	while (i < (len * 2))
	{
		if ((i % 2) == 0)
			(*file_hash)[i] = (uint32_t)(hash[i / 2] >> 32);
		else
			(*file_hash)[i] = (hash[i / 2] & 0xFFFFFFFF);
		i++;
	}
}
