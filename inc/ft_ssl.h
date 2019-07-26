/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:36:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/25 15:34:47 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define _P 1
# define _Q 2
# define _R 4
# define _S 8

enum	e_ssl_algorithm
{
	md5,
	sha256
};

typedef struct	s_file
{
	char	*file_name;
	char	*data;
}				t_file;

typedef struct	s_ssl_checksum
{
	enum e_ssl_algorithm	type;
	char					options;
	t_file					*files;
	char					*hash;
	size_t					len;
}				t_ssl_checksum;

#endif
