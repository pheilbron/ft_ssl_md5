/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:23:22 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/30 11:23:07 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_error.h"
#include "ft_dstring.h"

void		print_usage(t_ssl_checksum chk)
{
	t_dstring	*s;

	s = ft_dstr_init();
	if (chk->algorithm.type == message_digest)
		printf("usage: ft_ssl %s [-%s] [-s string] [files ...]\n",
				(chk.algorithm ? chk.algorithm.name : "command"),
				get_ssl_options(s, chk.algorithm.type)->buf);
	ft_dstr_free(s);
}

static void	print_commands(void)
{
	t_dstring		*s;
	if ((s = ft_dstr_init()))
	{
		printf("\nStandard commands:\n%s",
				get_ssl_commands(s, standard)->buf);
		s->pos = 0;
		printf("Message Digest commands:\n%s",
				get_ssl_commands(s, message_digest)->buf);
		s->pos = 0;
		printf("Cipher commands:\n%s",
				get_ssl_commands(s, cipher)->buf);
	}
	ft_dstr_free(s);
}

void		print_fatal_error(t_error e, t_ssl_checksum chk)
{
	if (e.no == INV_COMMAND)
	{
		printf("ft_ssl: '%s' is an invalid command.\n", e.data);
		print_commands();
	}
	else if (e.no == INV_OPTION)
	{
		printf("ft_ssl: illegal option -- %s\n", e.data);
		print_usage(chk);
	}
	else if (e.no == INV_FILE || e.no == DIRECTORY)
		printf("ft_ssl: %s: %s: %s", chk.algorithm.name, e.data,
				(e.no == INV_FILE ? "No such file or directory" :
				 "Is a directory\n"));
}

void		print_non_fatal_error(t_ssl_file *file)
{
	if (file->fd == -1)
		ft_printf("%s\n", file->data);
}

void		set_ssl_error(t_ssl_file *file, t_error e)
{
	file->fd = -1;
	if (e.no == INV_FILE || e.no == DIRECTORY)
		file->data = sprintf("ft_ssl: %s: %s: %s", chk.algorithm.name, e.data,
				(e.no == INV_FILE ? "No such file or directory" :
				 "Is a directory"));
	else if (e.no == MISSING_ARG)
		file->data = sprintf("ft_ssl: %s: option requires an argument -- %s",
				chk.algorithm.name, chk.
