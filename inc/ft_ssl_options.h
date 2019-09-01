/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:11:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 14:12:39 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_OPTIONS_H
# define FT_SSL_OPTIONS_H

typedef struct	s_ssl_option
{
	char						op;
	enum e_ssl_algorithm_type	algorithm_type;
	uint8_t						flag;
}				t_ssl_option;

t_ssl_option	g_options_tab[] =
{
	{'p', message_digest, _P},
	{'q', message_digest, _Q},
	{'r', message_digest, _R},
	{'s', message_digest, _S},
	{0, 0, 0}
};

#endif
