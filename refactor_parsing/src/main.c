/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:38:59 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/05 19:41:10 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ssl.h"
#include "ft_queue.h"
#include "ft_printf.h"

static t_ssl_checksum    *init_checksum(void)
{
	t_ssl_checksum	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	if (!(ret->files = ft_queue_init()))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

int						main(int ac, char **av)
{
	t_ssl_checksum	*chk;

	if ((chk = init_checksum()))
	{
		if (parse_input(chk, av + 1, ac - 1))
		{
			ft_ssl_process_and_print(chk);
			free(chk);
		}
	}
	else
		ft_printf("\n");
	system("leaks ft_ssl");
	return (0);
}