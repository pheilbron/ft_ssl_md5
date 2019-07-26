/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_checksum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:48:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/25 20:03:03 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

extern t_ssl_algorithm	g_algo_tab[];

char	*(*get_ssl_algorithm(enum e_ssl_algorithm_type type))(char *)
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
	 

void	ft_ssl_compute_checksum(t_ssl_checksum *chk)
{
	int	i;

	i = 0;
	while (i < chk->len)
	{
		chk->hash[i] = (*get_ssl_algorithm)(chk->type)(chk->file->data);
		i++;
	}
}
