/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 09:08:23 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/28 12:00:13 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ssl.h"
#include "ft_ssl_error.h"
#include "ft_ssl_algorithm.h"
#include "ft_string.h"
#include "ft_dstring.h"

extern t_ssl_algorithm	g_algo_tab[];
extern t_ssl_options	g_options_tab[];

t_error parse_ssl_command(t_ssl_checksum *chk, char *data, t_error *e)
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

t_error parse_ssl_file_stdin(t_ssl_checksum *chk, t_error *e)
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

t_error	set_ssl_option(t_ssl_checksum *chk, char op, t_error *e)
{
	int	i;

	i = 0;
	while (g_options_tab[i])
	{
		if (g_options_tab[i].op == op)
		{
			chk->options |= g_options_tab[i].flag;
			e->no = 1;
			return (*e);
		}
		i++;
	}
	e->no = INV_OPTION;
	return (*e);
}

t_error parse_ssl_options(t_ssl_checksum *chk, char **data, int *i, t_error *e)
{
	int	op_i;
	int	data_i;

	while (data[*i][0] = '-')
	{
		data_i = 1;
		while (data[*i][data_i])
			if ((set_ssl_option(chk, data[*i][data_i++], e)).no < 0)
				return (*e);
		(*i)++;
	}
	e->no = 1;
	return (*e);
}

void    parse_ssl_string(t_ssl_checksum *chk, char **data, int *i, t_error *e)
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

int	parse_ssl_file(t_ssl_checksum *chk, char **data, int i, t_error *e)
{
	t_ssl_file	*file;

	if (!(file = malloc(sizeof(*file))))
		return (e->no = INV_MALLOC);
	file->file_name = data[i];
	file->print_flag = (chk->options & ~_S) & ~_P;
	ft_vect_add(chk->files, file);
	return (e->no = 1);
}
