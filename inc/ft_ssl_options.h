/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:11:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/25 21:05:37 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_OPTION_H
# define FT_SSL_OPTION_H

typedef struct	s_ssl_option
{
	char	type;
	void	(*set)();
	void	(*f)();
}				t_ssl_option;

t_ssl_option	g_op_tab = {
	{'p', &set_stdin_option, NULL},
	{'q', &set_quiet_option, &ft_ssl_quiet},
	{'r', &set_rev_form_option, &ft_ssl_reverse},
	{'s', &set_print_option, &ft_ssl_print},
	{0, NULL, &ft_ssl_stdprint}
};

#endif
