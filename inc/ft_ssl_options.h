/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:11:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 13:20:24 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_OPTION_H
# define FT_SSL_OPTION_H

typedef struct	s_ssl_option
{
	char					op;
	enum e_ssl_algorithm	algorithm_type;
	uint8_t					flag;
	void					(*f)();
}				t_ssl_option;

#endif
