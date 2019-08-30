/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:11:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/30 11:26:05 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_OPTIONS_H
# define FT_SSL_OPTIONS_H

typedef struct	s_ssl_option
{
	char					op;
	enum e_ssl_algorithm	algorithm_type;
	uint8_t					flag;
	void					(*f)();
}				t_ssl_option;

t_ssl_option	g_options_tab[] =
{
	{'p', message_digest, _P, NULL},
	{'q', message_digest, _Q, &ft_ssl_md_quiet},
	{'r', message_digest, _R, &ft_ssl_md_reverse},
	{'s', message_digest, _S, &ft_ssl_md_print},
	{0, 0, 0, &ft_ssl_md_stdprint}
};

#endif
