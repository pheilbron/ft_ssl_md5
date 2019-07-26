/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:37:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/25 19:43:22 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libft.h"

extern t_err_message	g_error_tab[];

void	print_usage(void)
{
	printf("usage: ft_ssl command [-%s] [-s string] [files ...]\n",
			get_ssl_options().buf);
}

void	print_errno(t_error e, t_ssl_checksum chk)
{
	printf("%s: %s: %s\n",
			get_command(chk.type), e.data, g_error_tab[e.no * -1].message);
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
