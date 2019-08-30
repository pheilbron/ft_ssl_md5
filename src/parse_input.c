/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:00:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/30 12:17:13 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ssl.h"
#include "ft_ssl_error.h"
#include "ft_string.h"
#include "ft_dstring.h"
#include "ft_vector.h"

extern t_ssl_algorithm	g_algo_tab[];

static t_error	parse_ssl_command(t_ssl_checksum *chk, char *data, t_error *e)
{
	int	i;

	i = 0;
	while (g_algo_tab[i])
	{
		if (ft_strcmp(data, g_algo_tab[i].name) == 0)
		{
			chk->algorithm.name = data;
			chk->algorithm.algorithm = g_algo_tab[i].algorithm;
			chk->algorithm.type = g_algo_tab[i].type;
			chk->algorithm.f = g_algo_tab[i].f;
			e->no = 1;
			return (*e);
		}
		i++;
	}
	e->no = INV_COMMAND;
	e->data = data;
	return (*e);
}

static t_error	parse_ssl_file_stdin(t_ssl_checksum *chk, t_error *e)
{
	t_dstring	*s;
	char		read_buff[4096]
	int			size;
	t_ssl_file	*file;

	if (!(file = malloc(sizeof(*file))))
	{
		e->no = INV_MALLOC;
		return (*e);
	}
	read_buff = ft_dstr_init();
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

static void		parse_ssl_string(t_ssl_checksum *chk, char **data, int *i,
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
		e->no = INV_MALLOC;
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

	if (!(file = malloc(sizeof(*file))))
		return (e->no = INV_MALLOC);
	file->file_name = data[i];
	file->print_flag = (chk->options & ~_S) & ~_P;
	ft_vect_add(chk->files, file);
	return (e->no = 1);
}

int				parse_input(t_ssl_checksum *chk, char **data, size_t len)
{
	int		i;
	t_error	e;

	i = 0;
	if (len == 0)
		e.no = print_usage(*chk);
	else if (parse_ssl_command(chk, data[i++], &e).no < 0)
		print_fatal_error(e, *chk);
	else if (len == 1 && parse_ssl_file_stdin(chk, &e).no < 0)
		print_fatal_error(e, *chk);
	else if (parse_ssl_options(chk, data, &i, &e).no < 0)
		print_fatal_error(e, *chk);
	else if ((chk->options & _P) == _P && parse_ssl_file_stdin(chk, &e).no < 0)
		print_fatal_error(e, *chk); //not sure if it is possible to get an error
	else
	{
		if (chk->algorithm.type == message_digest && (chk->options & _S) == _S
			&& (parse_ssl_string(chk, (i < len ? data : NULL), &i, &e)).no < 0
			&& e.no != SYS_ERROR)
			set_ssl_error((t_ssl_file *)(chk->files[chk->files->pos - 1]), e);
		while (i < len)
			parse_ssl_file(chk, data, i++, &e);
	}
	return (e.no < 0 ? 0 : 1);
}
