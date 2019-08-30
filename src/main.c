/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:38:59 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/30 11:10:34 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ssl.h"

int	main(int ac, char **av)
{
	t_ssl_checksum	*chk;

	if (!(chk = malloc(sizeof(*chk))) || !(chk->files = ft_vect_new(4)))
		return (0);
	if (parse_input(chk, av, ac))
	{
		ft_ssl_compute_checksum(chk);
		ft_ssl_print_all(chk);
	}
	return (0);
}
