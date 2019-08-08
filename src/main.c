/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:38:59 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/07 19:44:58 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_ssl_checksum	*chk;

	if (!parse_input(chk, av, ac))
		ft_ssl_print_error(chk);
	else
	{
		ft_ssl_compute_checksum(chk);
		ft_ssl_print_all(chk);
	}
	return (0);
}
