/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:00:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/28 12:00:16 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_error.h"

int	parse_input(t_ssl_checksum *chk, char **data, size_t len)
{
	int 	i;
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
