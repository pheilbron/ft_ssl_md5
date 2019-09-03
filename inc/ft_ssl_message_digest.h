/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_message_digest.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:23:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 17:10:16 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MESSAGE_DIGEST_H
# define FT_SSL_MESSAGE_DIGEST_H

# include <stdint.h>
# include "ft_ssl.h"
# include "ft_ssl_md5.h"

#define LEADING_ONE ((uint32_t)1 << 31)
#define FIRST_HALF(x) x / ((uint64_t)1 << 32)
#define SECOND_HALF(x) x % ((uint64_t)1 << 32)

uint32_t	rotate_l(uint32_t, uint8_t shift);
uint32_t	rotate_r(uint32_t, uint8_t shift);
void		set_4b_file_hash(uint32_t *hash, uint32_t **file_hash, uint8_t len);

void		ft_ssl_md_print(char *algo_name, uint8_t algo_ops, uint8_t hash_len,
		t_ssl_file *file);

#endif
