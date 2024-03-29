/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:00:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/04 18:14:36 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_ssl.h"
#include "ft_ssl_options.h"
#include "ft_ssl_message_digest.h"
#include "ft_ssl_error.h"
#include "ft_string.h"
#include "ft_dstring.h"
#include "ft_vector.h"
#include "ft_stdlib.h"

t_ssl_algorithm	g_algo_tab[] = 
{
	{md5, "md5", message_digest, &ft_ssl_md5, &ft_ssl_md_print, 4},
	{sha1, "sha1", message_digest, &ft_ssl_sha1, &ft_ssl_md_print, 5},
	{sha224, "sha224", message_digest, &ft_ssl_sha224, &ft_ssl_md_print, 7},
	{sha256, "sha256", message_digest, &ft_ssl_sha256, &ft_ssl_md_print, 8},
	{sha384, "sha384", message_digest, &ft_ssl_sha384, &ft_ssl_md_print, 12},
	{sha512, "sha512", message_digest, &ft_ssl_sha512, &ft_ssl_md_print, 16},
	{0, NULL, 0, NULL, NULL, 0}
};

static t_error	parse_ssl_command(t_ssl_checksum *chk, char *data, t_error *e)
{
	int	i;

	i = 0;
	while (g_algo_tab[i].algorithm)
	{
		if (ft_strcmp(data, g_algo_tab[i].name) == 0)
		{
			chk->algorithm.name = data;
			chk->algorithm.algorithm = g_algo_tab[i].algorithm;
			chk->algorithm.type = g_algo_tab[i].type;
			chk->algorithm.f = g_algo_tab[i].f;
			chk->algorithm.print = g_algo_tab[i].print;
			chk->algorithm.hash_len = g_algo_tab[i].hash_len;
			e->no = 1;
			return (*e);
		}
		i++;
	}
	chk->algorithm.algorithm = 0;
	e->no = INV_COMMAND;
	e->data = data;
	return (*e);
}

static t_error	parse_ssl_file_stdin(t_ssl_checksum *chk, t_error *e)
{
	t_dstring	*s;
	char		read_buff[4096];
	int			size;
	t_ssl_file	*file;

	if (!(file = malloc(sizeof(*file))))
	{
		e->no = SYS_ERROR;
		return (*e);
	}
	s = ft_dstr_init();
	while ((size = read(0, read_buff, 4096)) > 0)
		ft_dstr_add(s, read_buff, size);
	file->fd = 0;
	file->file_name = NULL;
	file->data = ft_dstr_release(s);
	file->print_flag = _P;
	ft_vect_add(chk->files, file);
	e->no = 1;
	return (*e);
}

static t_error	parse_ssl_string(t_ssl_checksum *chk, char **data, int *i,
		t_error *e)
{
	t_ssl_file	*file;

	if (!data)
	{
		e->no = MISSING_ARG;
		return (*e);
	}
	if (!(file = malloc(sizeof(*file))))
	{
		e->no = SYS_ERROR;
		return (*e);
	}
	file->fd = 0;
	file->file_name = NULL;
	file->data = data[(*i)++];
	file->print_flag = _S;
	ft_vect_add(chk->files, file);
	e->no = 1;
	return (*e);
}

static int		parse_ssl_file(t_ssl_checksum *chk, char **data, int i,
		t_error *e)
{
	t_ssl_file	*file;
	t_dstring	*s;
	char		read_buff[4096];
	int			size;

	if (!(file = malloc(sizeof(*file))))
		return (e->no = SYS_ERROR);
	if ((file->fd = open(data[i], O_DIRECTORY)))
	{
		close(file->fd);
		return (e->no = DIRECTORY);
	}
	if ((file->fd = open(data[i], O_RDONLY)) < 0)
		return (e->no = INV_FILE);
	s = ft_dstr_init();
	while ((size = read(0, read_buff, 4096)) > 0)
		ft_dstr_add(s, read_buff, size);
	file->file_name = data[i];
	file->print_flag = (chk->options & (~_S & ~_P));
	ft_vect_add(chk->files, file);
	return (e->no = 1);
}

// fix flag parsing (if md5 -s -q, this would be incorrect)
// allow for multiple -s "asdf"

int				parse_input(t_ssl_checksum *chk, char **data, size_t len)
{
	int		i;
	t_error	e;

	i = 0;
	ft_ssl_error_init(&e);
	if (len == 0)
		print_usage(*chk);
	else if (parse_ssl_command(chk, data[i++], &e).no < 0)
		print_fatal_error(e, *chk);
	else if (len == 1 && parse_ssl_file_stdin(chk, &e).no < 0)
		print_fatal_error(e, *chk);
	else if (parse_ssl_options(chk, data, &i, &e).no < 0)
		print_fatal_error(e, *chk);
	else if ((chk->options & _P) == _P && parse_ssl_file_stdin(chk, &e).no < 0)
		print_fatal_error(e, *chk); //not sure if possible to get error
	else if (((chk->options & _S) == _S) &&
			(parse_ssl_string(chk, (i < (int)len ? data : NULL), &i, &e)).no < 0
			&& e.no != SYS_ERROR)
		set_ssl_error((t_ssl_file *)(chk->files->data[chk->files->pos - 1]),
				chk->algorithm.name, e);
	else
		while (i < (int)len)
			parse_ssl_file(chk, data, i++, &e);
	return (ft_ssl_free_error(&e) < 0 ? 0 : 1);
}
