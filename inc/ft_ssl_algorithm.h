/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_algorithm.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:35:33 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/25 15:40:09 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_ALGORITHM_H
# define FT_SSL_ALGORITHM_H

enum	e_ssl_algorithm_type
{
	standard,
	message_digest,
	cipher
};

typedef struct	s_ssl_algorithm
{
	enum e_ssl_algorithm		type;
	char						*name;
	enum e_ssl_algorithm_type	category;
}				t_ssl_algorithm;

t_ssl_algorithm	g_algo_tab[] =
{
	{md5, "md5", message_digest},
	{sha256, "sha256", message_digest},
	NULL
};

#endif
