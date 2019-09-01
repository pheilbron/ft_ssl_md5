/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:46:23 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 15:52:18 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	ft_ssl_free_error(t_error *e)
{
	int	error_no;

	error_no = e->no;
	if (e->no == INV_COMMAND)
		free(e->data);
	free(e);
	return (error_no);
}
