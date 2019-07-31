/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:37:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 13:58:21 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

void	print_usage(void)
{
	printf("usage: ft_ssl command [-%s] [-s string] [files ...]\n",
			get_ssl_options().buf);
}

void	print_errno(t_error e, t_ssl_checksum chk)
{
	t_err_message	error_tab[] = {{0, "",},
		{INV_COMMAND, "is an invalid command."}, {INV_OPTION, "illegal option"},
		{INV_FILE, "No such file or directory"}, {DIRECTORY, "Is a directory"}};
	printf("%s: %s: %s\n",
			get_command(chk.type), e.data, error_tab[e.no * -1].message);
	if (errno == INV_OPTION)
		print_usage();
	else if (errno == INV_COMMAND)
		printf("\nStandard commands:\n%s
				Message Digest commands:\n%s
				Cipher commands:\n%s",
				get_ssl_commands(standard).buf,
				get_ssl_commands(message_digest).buf,
				get_ssl_commands(cipher).buf);
}
