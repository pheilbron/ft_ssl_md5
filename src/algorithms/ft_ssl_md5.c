/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:43:49 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 17:13:23 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "ft_ssl.h"
#include "ft_string.h"

#define INIT 1
#define INIT_TEMP 2
#define SHIFT_TEMP 3

#define LEADING_ONE ((uint32_t)1 << 31)
#define FIRST_HALF(x) x / ((uint64_t)1 << 32)
#define SECOND_HALF(x) x % ((uint64_t)1 << 32)

static size_t	pad_data(char *data, t_md5_chunk *chunk)
{
	uint64_t	len;
	uint64_t	i;
	uint64_t	chunk_len;

	i = 0;
	len = ft_strlen(data) * sizeof(*data);
	chunk_len = ((len / 4) + (16 - ((len / 4) % 16)));
	if ((chunk->data = malloc(sizeof(*chunk->data) * chunk_len)))
	{
		i = ft_ssl_prep_4b_data(&(chunk->data), data, len);
		chunk->data[i++] = LEADING_ONE;
		while (i < chunk_len - 2)
			chunk->data[i++] = 0;
		chunk->data[i++] = (uint32_t)(FIRST_HALF(len));
		chunk->data[i] = (uint32_t)(SECOND_HALF(len));
	}
	return (chunk_len);
}

static int		shift(int x, int i)
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

static void		set_abcd(t_md5_chunk *chunk, int type, int append)
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
		chunk->c = chunk->b;
		chunk->b += append;
	}
}

static void		iterate(t_md5_chunk *chunk, int i)
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
	else
	{
		temp = chunk->c ^ (chunk->b | ~(chunk->d));
		chunk_i = (i * 7) % 16;
	}
	set_abcd(chunk, SHIFT_TEMP, chunk->data[chunk->pos + chunk_i] + chunk->a +
			temp + shift((unsigned int)floor(chunk->c * fabs(sin(i + 1))), i));
}

void			ft_ssl_md5(char *data, uint32_t (*hash)[4])
{
	t_md5_chunk	chunk;
	size_t		len;
	size_t		i;

	len = pad_data(data, &chunk);
	set_abcd(&chunk, INIT, 0);
	while (len > 0)
	{
		i = 0;
		set_abcd(&chunk, INIT_TEMP, 0);
		while (i < 64)
			iterate(&chunk, i);
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
	free(chunk.data);
}
