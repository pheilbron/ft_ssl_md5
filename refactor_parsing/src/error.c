/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:23:22 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/05 19:52:53 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_error.h"
#include "ft_stdio.h"
#include "ft_printf.h"
#include "ft_dstring.h"

int			print_usage(t_ssl_checksum chk)
{
	t_dstring	*s;

	s = ft_dstr_init();
	if (chk.algorithm.type == message_digest)
		ft_printf("usage: ft_ssl %s [-%s] [-s string] [files ...]\n",
				(chk.algorithm.algorithm ? chk.algorithm.name : "command"),
				get_ssl_options(s, chk.algorithm.type)->buf);
	else
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	ft_dstr_free(s);
	return (0);
}

static void	print_commands(void)
{
	t_dstring		*s;

	if ((s = ft_dstr_init()))
	{
		ft_printf("\nStandard commands:\n%s\n",
				get_ssl_commands(s, standard)->buf);
		s->pos = 0;
		ft_printf("Message Digest commands:\n%s\n",
				get_ssl_commands(s, message_digest)->buf);
		s->pos = 0;
		ft_printf("Cipher commands:\n%s\n",
				get_ssl_commands(s, cipher)->buf);
	}
	ft_dstr_free(s);
}

int			print_fatal_error(t_ssl_checksum chk)
{
	if (chk.e.no == INV_COMMAND)
	{
		ft_printf("ft_ssl: '%s' is an invalid command.\n", chk.e.data);
		print_commands();
	}
	else if (chk.e.no == INV_OPTION)
	{
		ft_printf("ft_ssl: illegal option -- %s\n", chk.e.data);
		print_usage(chk);
	}
	return (0);
}

void		print_non_fatal_error(t_ssl_file *file, char *algorithm_name)
{
	t_dstring	*s;

	file->fd = PARSE_ERROR;
	s = ft_dstr_init();
	if (file->e.no == INV_FILE || file->e.no == DIRECTORY)
		ft_dstr_addf(s, "ft_ssl: %s: %s: %s", algorithm_name,
				file->e.data, (file->e.no == INV_FILE ?
					"No such file or directory" : "Is a directory"));
	else if (file->e.no == MISSING_ARG)
		ft_dstr_addf(s, "ft_ssl: %s: option requires an argument -- s",
				algorithm_name);
	if (file->e.no == INV_FILE || file->e.no == DIRECTORY ||
			file->e.no == MISSING_ARG)
		ft_printf("%s\n", (file->data = ft_dstr_release(s)));
	else
		file->fd = NO_DATA_MALLOC;
}

void		set_ssl_error(t_ssl_file *file, char *algorithm_name, t_error e)
{
	t_dstring	*s;

	file->fd = PARSE_ERROR;
	s = ft_dstr_init();
	if (e.no == INV_FILE || e.no == DIRECTORY)
		ft_dstr_addf(s, "ft_ssl: %s: %s: %s", algorithm_name,
				e.data, (e.no == INV_FILE ? "No such file or directory"
					: "Is a directory"));
	else if (e.no == MISSING_ARG)
		ft_dstr_addf(s, "ft_ssl: %s: option requires an argument -- s",
				algorithm_name);
	if (e.no == INV_FILE || e.no == DIRECTORY || e.no == MISSING_ARG)
		file->data = ft_dstr_release(s);
	else
		file->fd = NO_DATA_MALLOC;
}

void		ft_ssl_error_init(t_error *e)
{
	e->no = 0;
	e->data = NULL;
}

int			ft_ssl_new_error(t_error *e, int no, char *data)
{
	e->no = no;
	e->data = data;
	return (no);
}
