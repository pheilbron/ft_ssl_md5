/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:00:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 17:14:00 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_ssl.h"
#include "ft_ssl_md.h"
#include "ft_ssl_md5.h"
#include "ft_string.h"
#include "ft_dstring.h"
#include "ft_vector.h"
#include "ft_stdlib.h"

extern t_ssl_algorithm	g_algo_tab[];

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
	char		*line;

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
	while (get_next_line(file->fd, &line) > 0)
		ft_dstr_addf(s, "%s\n", line);
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
	if (len == 0)
		return (print_usage(*chk));
	if (parse_ssl_command(chk, data[i++], &e).no < 0)
		return (print_fatal_error(e, *chk));
	if (len == 1 && parse_ssl_file_stdin(chk, &e).no < 0)
		return (print_fatal_error(e, *chk));
	if (parse_ssl_options(chk, data, &i, &e).no < 0)
		return (print_fatal_error(e, *chk));
	if ((chk->options & _P) == _P && parse_ssl_file_stdin(chk, &e).no < 0)
		return (print_fatal_error(e, *chk)); //not sure if possible to get error
	if (chk->algorithm.type == message_digest && (chk->options & _S) == _S &&
			(parse_ssl_string(chk, (i < (int)len ? data : NULL), &i, &e)).no < 0
			&& e.no != SYS_ERROR)
		set_ssl_error((t_ssl_file *)(chk->files->data[chk->files->pos - 1]),
				chk->algorithm.name, e);
	while (i < (int)len)
		parse_ssl_file(chk, data, i++, &e);
	return (ft_ssl_free_error(&e) < 0 ? 0 : 1);
}
