/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:54:01 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/05 18:11:39 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include <stdint.h>

#define A 0
#define B 1
#define C 2
#define D 3

typedef struct	s_md5_chunk
{
	uint32_t	*data;
	uint32_t	len;
	uint32_t	pos;
	uint32_t	hash[4];
	uint32_t	temp[4];
}				t_md5_chunk;

void			ft_ssl_md5(char *data, uint32_t **hash);

#endif
