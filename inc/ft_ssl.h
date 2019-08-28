/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:36:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/28 12:00:23 by pheilbro         ###   ########.fr       */
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

enum	e_ssl_algorithm_type
{
	standard,
	message_digest,
	cipher
};

typedef struct	s_ssl_algorithm
{
	enum e_ssl_algorithm		algorithm;
	char						*name;
	enum e_ssl_algorithm_type	type;
	void						(*f)();
}				t_ssl_algorithm;

typedef struct	s_ssl_file
{
	int			fd;
	char		*file_name;
	char		*data;
	uint8_t		print_flag;
	uint32_t	*hash;
}				t_ssl_file;

typedef struct	s_ssl_checksum
{
	t_ssl_algorithm	algorithm
	uint8_t			options;
	t_vector		*files;
}				t_ssl_checksum;

#endif
