/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_sha256.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:02:15 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 17:12:31 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_SHA256_H
# define FT_SSL_SHA256_H

typedef struct	s_sha256_chunk
{
	uint32_t	*data;
	uint32_t	len;
	uint32_t	pos;
	uint32_t	s[64];
	uint32_t	hash[8];
	uint32_t	temp[8];
}				t_sha256_chunk;

void	ft_ssl_sha256(char *data, uint32_t **file_hash);

#endif
