/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:10:42 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/04 22:18:25 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//take 2


enum	e_ssl_algorithm
{
	md5 = 1,
	sha1,
	sha224,
	sha256,
	sha384,
	sha512
};

enum	e_ssl_algorithm_type
{
	standard = 1,
	message_digest,
	cipher
};

typedef struct	s_ssl_file
{
	char		*file_name;
	char		*data;
	uint8_t		print_flag;
	uint32_t	*hash;
	uint8_t		hash_len;
	t_error		e;
}				t_ssl_file;

typedef struct	s_ssl_algorithm
{
	enum e_ssl_algorithm		algorithm;
	char						*name;
	enum e_ssl_algorithm_type	type;
	void						(*f)();
	void						(*print)();
}				t_ssl_algorithm;

typedef struct	s_ssl_md_context
{
	t_ssl_algorithm	algorithm;
	uint8_t			options;
	t_queue			*files;
	t_error			e;
}				t_ssl_md_context;
