/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:38:59 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 11:01:44 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ssl.h"
#include "ft_vector.h"
#include "ft_printf.h"

static void	ft_ssl_free_checksum(t_ssl_checksum *chk)
{
	int			i;
	t_ssl_file	*file;

	i = 0;
	while (i < chk->files->pos)
	{
		file = (t_ssl_file *)(chk->files->data[i]);
		if (file->fd > 0)
			free(file->hash);
	//	if (file->fd != NO_DATA_MALLOC && file->data)
	//		free(file->data);
		i++;
	}
	ft_vect_free(chk->files);
	free(chk);
}

int			main(int ac, char **av)
{
	t_ssl_checksum	*chk;

	chk = malloc(sizeof(*chk));
	if (!chk || !(chk->files = ft_vect_new(4)))
	{
		free(chk);
		return (0);
	}
	if (parse_input(chk, av + 1, ac - 1))
		ft_ssl_process_and_print(chk);
	ft_ssl_free_checksum(chk);
	return (0);
}
