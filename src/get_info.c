/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:41:21 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 14:06:58 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_algorithm.h"
#include "ft_ssl_option.h"
#include "libft.h"

extern t_ssl_algorithm	g_algo_tab[];

t_dstring	get_ssl_options(enum e_ssl_algorithm_type type)
{
	int 			i;
	t_dstring		ret;
	t_ssl_option	options_tab = {{'p', message_digest, _P, NULL},
		{'q', message_digest, _Q, &ft_ssl_quiet},
		{'r', message_digest, _R, &ft_ssl_reverse},
		{'s', message_digest, _S, &ft_ssl_print}, {0, 0, 0, &ft_ssl_stdprint}};

	i = 0;
	ft_dstr_init(&ret);
	while (options_tab[i])
	{
		if (options_tab[i].algorithm_type == type && options_tab[i].op != 's')
			ft_dstr_add(&ret, options_tab[i].type, 1);
		i++;
	}
	ft_dstr_add(&ret, "\0", 1);
	return (ret);
}

char		*get_ssl_command(enum e_ssl_algorithm type)
{
	int	i;

	i = 0;
	while (g_algo_tab[i])
	{
		if (g_algo_tab[i].algorithm == type)
			return (g_algo_tab[i].name);
		i++;
	}
	return (NULL);
}

t_dstring	*get_ssl_commands(t_dstring *s, enum e_ssl_algorithm_type category)
{
	int			i;

	i = 0;
	while (g_algo_tab[i])
	{
		if (g_algo_tab[i].type == category)
			ft_dstr_overwrite(s, g_algo_tab[i].name,
					ft_strlen(g_algo_tab[i].name));
		ft_dstr_add(s, "\n", 1);
		i++;
	}
	return (s);
}
