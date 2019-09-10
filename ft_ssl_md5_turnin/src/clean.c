/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:46:23 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 10:43:58 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ssl_error.h"
#include "ft_ssl_options.h"
#include "ft_ssl.h"

int	ft_ssl_free_error(t_error *e)
{
	int	error_no;

	error_no = e->no;
	if (e->no == INV_COMMAND)
		free(e->data);
	return (error_no);
}

int	ft_ssl_free_file(t_ssl_file *file)
{
	if (file->fd >= 0)
		free(file->hash);
	if (file->data && file->fd != PARSE_ERROR && ((file->flag & _S) != _S))
		free(file->data);
	free(file);
	return (1);
}
