/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:49:40 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 15:59:07 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	ft_ssl_prep_4b_data(uint32_t **prepped_data, char *data, uint32_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		(*prepped_data)[i] = data[(i * 4)] + data[(i * 4) + 1] +
			data[(i * 4) + 2] + data[(i * 4) + 3];
		i++;
	}
	return (i);
}
