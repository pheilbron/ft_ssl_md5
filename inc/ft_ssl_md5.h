/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:54:01 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 17:14:43 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include <stdint.h>

typedef struct	s_md5_chunk
{
	uint32_t	*data;
	size_t		len;
	size_t		pos;
	uint32_t	abcd[4];
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
}				t_md5_chunk;

void			ft_ssl_md5(char *data, uint32_t (*hash)[4]);

#endif
