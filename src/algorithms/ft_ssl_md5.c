/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:43:49 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 11:13:06 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_ssl.h"
#include "ft_ssl_md5.h"

#define INIT 1
#define INIT_TEMP 2
#define SHIFT_TEMP 3

size_t	md5_pad_data(char *data, t_md5_chunk *chunk)
{
	uint32_t	len;
	int			i;

	i = 0;
	len = ft_strlen(data) * sizeof(*data);
	if ((chunk->padded_data = malloc(sizeof(*chunk->padded_data) * len
}

int		shift(int x, int i)
{
	int	shift;

	shift = 0;
	if (i >= 0 && i < 16)
		shift = 7 + (5 * (i % 4));
	if (i >= 16 && i < 32)
		shift = (5 * ((i + 1) % 4)) - (i % 3 > 0 ? 1 : 0);
	if (i >= 32 && i < 48)
		shift = (i % 4) + ((i % 2) * 2) + (((i + 1) % 2) * ((i / 2) * 3));
	if (i >= 48 && i < 64)
		shift = (5 * ((i + 1) % 4)) - (i % 3 > 0 ? 0 : 1);
	return (x << shift | x >> shift);
}

void	md5_set_abcd(t_md5_chunk *chunk, int type, int append)
{
	if (type == INIT)
	{
		chunk->pos = 0;
		chunk->abcd[0] = 0x67452301;
		chunk->abcd[1] = 0xefcdab89;
		chunk->abcd[2] = 0x98badcfe;
		chunk->abcd[3] = 0x10325476;
	}
	else if (type == INIT_TEMP)
	{
		chunk->a = chunk->abcd[0];
		chunk->b = chunk->abcd[1];
		chunk->c = chunk->abcd[2];
		chunk->d = chunk->abcd[3];
	}
	else if (type == SHIFT_TEMP)
	{
		chunk->a = chunk->d;
		chunk->d = chunk->c;
		chunk->c = chunk-b;
		chunk->b += append;
	}
}

void	md5_iterate(t_md5_chunk *chunk, int i)
{
	uint32_t	temp;
	int			chunk_i;

	if (i >= 0 && i < 16)
	{
		temp = (chunk->a & chunk->c) | ((~chunk->b) & chunk->d);
		chunk_i = i;
	}
	else if (i >= 16 && i < 32)
	{
		temp = (chunk->d & chunk->b) | (~(chunk->b) & chunk->c);
		chunk_i = ((i * 5) + 1) % 16;
	}
	else if (i >= 32 && i < 48)
	{
		temp = (chunk->b ^ chunk->c ^ chunk->d);
		chunk_i = ((i * 3) + 5) % 16;
	}
	else if (i >= 48 && i < 64)
	{
		temp = chunk->c ^ (chunk->b | ~(chunk->d));
		chunk_i = (i * 7) % 16;
	}
	md5_set_temp(chunk, SHIFT_TEMP, shift((unsigned int)floor(c * fabs(sin(i + 1)))
				+ chunk->padded_data[chunk->pos + chunk_i] + temp + chunk->a, i));
}

void	ft_ssl_md5(char *data, uint32_t (*hash)[4])
{
	t_md5_chunk	chunk;
	size_t		len;
	size_t		i;

	len = md5_pad_data(data, &chunk);
	md5_set_abcd(&chunk, INIT, 0);
	while (len > 0)
	{
		i = 0;
		md5_set_temp(&chunk, INIT_TEMP, 0);
		while (i < 64)
			md5_iterate(&chunk, i);
		chunk.abcd[0] += chunk.a;
		chunk.abcd[1] += chunk.b;
		chunk.abcd[2] += chunk.c;
		chunk.abcd[3] += chunk.d;
		chunk.pos += 16;
		len -= 16;
	}
	(*hash)[0] = chunk.abcd[0];
	(*hash)[1] = chunk.abcd[1];
	(*hash)[2] = chunk.abcd[2];
	(*hash)[3] = chunk.abcd[3];
	free(chunk.padded_data);
}
