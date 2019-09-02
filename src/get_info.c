/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:41:21 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 17:10:30 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_options.h"
#include "ft_dstring.h"
#include "ft_string.h"

extern t_ssl_algorithm	g_algo_tab[];
extern t_ssl_option		g_options_tab[];

t_dstring	*get_ssl_options(t_dstring *s, enum e_ssl_algorithm_type type)
{
	int	i;

	i = 0;
	while (g_options_tab[i].op)
	{
		if (g_options_tab[i].algorithm_type == type)
			if (g_options_tab[i].algorithm_type != message_digest &&
					g_options_tab[i].op != 's')
				ft_dstr_add(s, &(g_options_tab[i].op), 1);
		i++;
	}
	ft_dstr_add(s, "\0", 1);
	return (s);
}

char		*get_ssl_command(enum e_ssl_algorithm type)
{
	int	i;

	i = 0;
	while (g_algo_tab[i].algorithm)
	{
		if (g_algo_tab[i].algorithm == type)
			return (g_algo_tab[i].name);
		i++;
	}
	return (NULL);
}

//fix so that the avaliable algorithms are printed lowercase

t_dstring	*get_ssl_commands(t_dstring *s, enum e_ssl_algorithm_type category)
{
	int	i;

	i = 0;
	while (g_algo_tab[i].algorithm)
	{
		if (g_algo_tab[i].type == category)
			ft_dstr_overwrite(s, g_algo_tab[i].name,
					ft_strlen(g_algo_tab[i].name));
		ft_dstr_add(s, "\n", 1);
		i++;
	}
	return (s);
}
