/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_checksum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:48:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/30 11:28:45 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"

extern t_ssl_algorithm	g_algo_tab[];

static void	(*get_ssl_algorithm(enum e_ssl_algorithm_type type))(char *, uint32_t *)
{
	int	i;

	i = 0;
	while (g_algo_tab[i])
	{
		if (g_algo_tab[i].type == type)
			return (g_algo_tab[i].f);
		i++;
	}
	return (NULL);
}

void		ft_ssl_compute_checksum(t_ssl_checksum *chk)
{
	int			i;
	t_ssl_file	*file;

	i = 0;
	while (i < chk->files->pos)
	{
		file = (t_ssl_file *)(chk->files->data[i]);
		if (file->fd == -1)
			print_non_fatal_error(file);
		else
			(*get_ssl_algorithm)(chk->type)(file->data, file->hash);
		i++;
	}
}
