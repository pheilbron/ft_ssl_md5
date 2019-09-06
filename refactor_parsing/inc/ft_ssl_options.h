/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:11:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 10:13:44 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_OPTIONS_H
# define FT_SSL_OPTIONS_H

# include "ft_ssl.h"

# define _P 1
# define _Q 2
# define _R 4
# define _S 8

typedef struct	s_ssl_option
{
	char						op;
	enum e_ssl_algorithm_type	algorithm_type;
	uint8_t						flag;
}				t_ssl_option;

extern t_ssl_option	g_options_tab[];

#endif
