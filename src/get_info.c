/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:41:21 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/25 19:18:14 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl_algorithm.h>
#include <ft_ssl_option.h>
#include <libft.h>

extern t_ssl_algorithm	g_algo_tab[];
extern t_ssl_option		g_op_tab[];

t_dstring	get_ssl_options(void)
{
	int 		i;
	t_dstring	ret;

	i = 0;
	ft_dstr_init(&ret);
	while (g_op_tab[i])
	{
		if (g_op_tab[i] != 's')
			ft_dstr_add(&ret, g_op_tab[i].type, 1);
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
		if (g_algo_tab[i].type == type)
			return (g_algo_tab[i].name);
		i++;
	}
	return (NULL);
}


t_dstring	get_ssl_commands(enum e_ssl_algorithm_type category)
{
	int			i;
	t_dstring	ret;

	i = 0;
	ft_dstr_init(&ret);
	while (g_algo_tab[i])
	{
		if (g_algo_tab[i].type == category)
			ft_dstr_add(&ret, g_algo_tab[i].name,
					ft_strlen(g_algo_tab[i].name));
		ft_dstr_add(&ret, "\n", 1);
		i++;
	}
	ft_dstr_add(&ret, "\0", 1);
	return (ret);
}
