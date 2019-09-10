/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:36:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 11:24:32 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include "ft_ssl_error.h"
# include "ft_queue.h"
# include "ft_dstring.h"

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
	int			fd;
	char		*name;
	char		*data;
	uint32_t	*hash;
	uint8_t		flag;
	t_error		e;
}				t_ssl_file;

typedef struct	s_ssl_algorithm
{
	enum e_ssl_algorithm		algorithm;
	char						*name;
	enum e_ssl_algorithm_type	type;
	void						(*f)();
	void						(*print)();
	uint8_t						hash_len;
}				t_ssl_algorithm;

typedef struct	s_ssl_checksum
{
	t_ssl_algorithm	algorithm;
	uint8_t			options;
	t_queue			*files;
	t_error			e;
}				t_ssl_checksum;

extern t_ssl_algorithm	g_algo_tab[];

t_dstring		*get_ssl_options(t_dstring *s, enum e_ssl_algorithm_type type);
char			*get_ssl_command(enum e_ssl_algorithm type);
t_dstring		*get_ssl_commands(t_dstring *s,
		enum e_ssl_algorithm_type category);

void			parse_message_digest(t_ssl_checksum *c, char **data,
		int len, int *i);
int				parse_input(t_ssl_checksum *c, char **data, int len);
int				set_ssl_option(t_ssl_checksum *c, char op);

int				ft_ssl_prep_4b_little_end(uint32_t **prepped_data, char *data,
		uint64_t len);
int				ft_ssl_prep_4b_big_end(uint32_t **prepped_data, char *data,
		uint64_t len);
int				ft_ssl_prep_8b_big_end(uint64_t **prepped_data, char *data,
		uint64_t len);

void			ft_ssl_process_and_print(t_ssl_checksum *chk);

int				print_usage(t_ssl_checksum chk);
int				print_fatal_error(t_ssl_checksum chk);
void			print_non_fatal_error(t_ssl_file *file, char *algorithm_name);
void			set_ssl_error(t_ssl_file *file, char *algorithm_name,
		t_error e);
void			ft_ssl_error_init(t_error *e);
int				ft_ssl_new_error(t_error *e, int no, char *data);

int				ft_ssl_free_error(t_error *e);
int				ft_ssl_free_file(t_ssl_file *file);

#endif
