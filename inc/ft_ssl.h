/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:36:05 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 11:41:23 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include "ft_ssl_error.h"
# include "ft_vector.h"
# include "ft_dstring.h"

enum	e_ssl_algorithm
{
	md5 = 1,
	sha256
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
	char		*file_name;
	char		*data;
	uint8_t		print_flag;
	uint32_t	*hash;
}				t_ssl_file;

typedef struct	s_ssl_algorithm
{
	enum e_ssl_algorithm		algorithm;
	char						*name;
	enum e_ssl_algorithm_type	type;
	void						(*f)();
	void						(*print)(char *, uint8_t, uint8_t,
			t_ssl_file *);
	uint8_t						hash_len;
}				t_ssl_algorithm;

typedef struct	s_ssl_checksum
{
	t_ssl_algorithm	algorithm;
	uint8_t			options;
	t_vector		*files;
}				t_ssl_checksum;

extern t_ssl_algorithm	g_algo_tab[];

t_dstring		*get_ssl_options(t_dstring *s, enum e_ssl_algorithm_type type);
char			*get_ssl_command(enum e_ssl_algorithm type);
t_dstring		*get_ssl_commands(t_dstring *s,
		enum e_ssl_algorithm_type category);

int				parse_input(t_ssl_checksum *chk, char **data, size_t len);
t_error			parse_ssl_options(t_ssl_checksum *chk, char **data, int *i,
		t_error *e);
	
int				ft_ssl_prep_4b_data(uint32_t **prepped_data, char *data,
		uint64_t len);

void			ft_ssl_process_and_print(t_ssl_checksum *chk);

int				print_usage(t_ssl_checksum chk);
int				print_fatal_error(t_error e, t_ssl_checksum chk);
void			print_non_fatal_error(t_ssl_file *file);
void			set_ssl_error(t_ssl_file *file, char *algorithm_name,
		t_error e);
void			ft_ssl_error_init(t_error *e);
int				ft_ssl_free_error(t_error *e);

#endif
