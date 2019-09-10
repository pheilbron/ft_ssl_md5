/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:14:21 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 14:59:52 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_dstring.h"

int	set_color_fstring(t_dstring *s, const char **f_string, int *pos)
{
	int				i;
	const t_color	color_tab[] = {{"{red}", "\x1b[31m"},
		{"{grn}", "\x1b[32m"}, {"{yel}", "\x1b[33m"},
		{"{blu}", "\x1b[34m"}, {"{mag}", "\x1b[35m"},
		{"{cyn}", "\x1b[36m"}, {"{eoc}", "\x1b[0m"},
		{NULL, NULL}};

	i = 0;
	while (color_tab[i].type && ft_memcmp(*f_string, color_tab[i].type, 5) != 0)
		i++;
	if (color_tab[i].type)
	{
		(*f_string) += 5;
		return (ft_dstr_add(s, color_tab[i].escape_code, (i != 7 ? 5 : 4)));
	}
	(*pos)++;
	return (0);
}
