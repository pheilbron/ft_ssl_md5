/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:36:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 11:47:00 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "ft_vector.h"
# include "ft_dstring.h"
# include "ft_ssl_error.h"
# include "ft_ssl_md5.h"

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
	t_ssl_algorithm	algorithm;
	uint8_t			options;
	t_vector		*files;
}				t_ssl_checksum;

t_ssl_algorithm	g_algo_tab[] =
{
	{md5, "md5", message_digest, &ft_ssl_md5},
//	{sha256, "sha256", message_digest, &ft_ssl_sha256},
	NULL
};

void			ft_ssl_compute_checksum(t_ssl_checksum *chk);

t_dstring		get_ssl_options(enum e_ssl_algorithm_type type);
char			*get_ssl_command(enum e_ssl_algorithm type);
t_dstring		*get_ssl_commands(t_dstring *s,
		enum e_ssl_algorithm_type category);

int				parse_input(t_ssl_checksum *chk, char **data, size_t len);

t_error			parse_ssl_options(t_ssl_checksum *chk, char **data, int *i,
		t_error *e);

t_error			parse_ssl_command(t_ssl_checksum *chk, char *data, t_error *e);
t_error			parse_ssl_file_stdin(t_ssl_checksum *chk, t_error *e);
void			parse_ssl_string(t_ssl_checksum *chk, char **data, int *i,
		t_error *e);
int				parse_ssl_file(t_ssl_checksum *chk, char **data, int i,
		t_error *e);

#endif
