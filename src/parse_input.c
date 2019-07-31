/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:00:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 13:55:26 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_error.h"

int	parse_input(t_ssl_checksum *chk, char **data, size_t len)
{
	int 			i;
	t_error			e;

	i = 0;
	if (len == 0)
		print_usage();
	else if (parse_ssl_command(chk, data[i++], &e).no < 0)
		print_error(e, *chk);
	else if (len == 1 && parse_ssl_file_stdin(chk, &e).no < 0)
		print_error(e, *chk);
	else if (parse_ssl_options(chk, data, &i, &e).no < 0)
		print_error(e, *chk);
	else if ((chk->options & _P) == _P && parse_ssl_file_stdin(chk, &e).no < 0)
		print_error(e, *chk);
	else
	{
		if ((chk->options & _S) == _S)
			parse_ssl_string(chk, data, &i, &e);
		if ((i < len) && parse_ssl_files(chk, data, i, &e).no < 0)
			print_error(e, *chk);
	}
	return (e.no < 0 ? 0 : 1);
}
