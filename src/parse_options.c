/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:34:53 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 14:30:33 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
//#include "ft_ssl_options.h"

extern t_ssl_option	g_options_tab[];

static t_error	set_ssl_option(t_ssl_checksum *chk, char op, t_error *e)
{
	int	i;

	i = 0;
	while (g_options_tab[i].op)
	{
		if (g_options_tab[i].op == op)
		{
			chk->options |= g_options_tab[i].flag;
			e->no = 1;
			return (*e);
		}
		i++;
	}
	e->no = INV_OPTION;
	return (*e);
}

t_error			parse_ssl_options(t_ssl_checksum *chk, char **data, int *i,
		t_error *e)
{
	int	data_i;

	while (data[*i][0] == '-')
	{
		data_i = 1;
		while (data[*i][data_i])
			if ((set_ssl_option(chk, data[*i][data_i++], e)).no < 0)
				return (*e);
		(*i)++;
	}
	e->no = 1;
	return (*e);
}
