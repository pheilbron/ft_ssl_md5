/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_message_digest.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:23:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 11:02:09 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MESSAGE_DIGEST_H
# define FT_SSL_MESSAGE_DIGEST_H

# include <stdint.h>
# include "ft_ssl.h"
# include "ft_ssl_md5.h"
# include "ft_ssl_sha1.h"
# include "ft_ssl_sha256.h"
# include "ft_ssl_sha512.h"

# define ULONG_LEADING_ONE ((uint32_t)1 << 31)
# define ULLONG_LEADING_ONE (uint64_t)1 << 63
# define FIRST_HALF(x) x / ((uint64_t)1 << 32)
# define SECOND_HALF(x) x % ((uint64_t)1 << 32)

uint64_t	rot_l(uint64_t x, uint8_t shift, uint8_t data_size);
uint64_t	rot_r(uint64_t x, uint8_t shift, uint8_t data_size);
void		set_4b_file_hash(uint32_t *hash, uint32_t **file_hash, uint8_t len);
void		set_4b_le_file_hash(uint32_t *hash, uint32_t **file_hash,
		uint8_t len);
void		set_8b_to_4b_file_hash(uint64_t *hash, uint32_t **file_hash,
		uint8_t len);

void		ft_ssl_md_print(t_ssl_file *file, t_ssl_checksum *c);

#endif
