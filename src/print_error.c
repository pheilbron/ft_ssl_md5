/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:37:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 13:53:11 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

void	print_usage(t_ssl_checksum chk)
{
	t_dstring	*s;

	s = ft_dstr_init(s);
	printf("usage: ft_ssl %s [-%s] [-s string] [files ...]\n",
			chk.algorithm.name,
			get_ssl_options(s, chk.algorithm.type)->buf);
	ft_dstr_free(s);
}

void	print_errno(t_error e, t_ssl_checksum chk)
{
	t_dstring		*s;
	t_err_message	error_tab[] = {{0, "",},
		{INV_COMMAND, "is an invalid command."}, {INV_OPTION, "illegal option"},
		{INV_FILE, "No such file or directory"}, {DIRECTORY, "Is a directory"}};

	s = ft_dstr_init(s);
	printf("%s: %s: %s\n",
			get_command(chk.algorithm.algorithm), e.data,
			error_tab[e.no * -1].message);
	if (errno == INV_OPTION)
		print_usage(chk);
	else if (errno == INV_COMMAND)
		printf("\nStandard commands:\n%s
				Message Digest commands:\n%s
				Cipher commands:\n%s",
				get_ssl_commands(s, standard)->buf,
				get_ssl_commands(s, message_digest)->buf,
				get_ssl_commands(s, cipher)->buf);
	ft_dstr_free(s);
}
