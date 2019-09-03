/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:49:40 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 20:03:29 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	ft_ssl_prep_4b_little_end(uint32_t **prepped_data, char *data, uint64_t len)
{
	uint64_t data_i;
	int	pdata_i;

	data_i = 0;
	pdata_i = 0;
	(*prepped_data)[pdata_i] = 0;
	while (data_i < len)
	{
		(*prepped_data)[pdata_i] += (((uint32_t)(data[data_i])) <<
				((data_i % 4) * 8));
		if (data_i % 4 == 3)
			(*prepped_data)[++pdata_i] = 0;
		data_i++;
	}
	return (pdata_i);
}

int	ft_ssl_prep_4b_big_end(uint32_t **prepped_data, char *data, uint64_t len)
{
	uint64_t data_i;
	int	pdata_i;

	data_i = 0;
	pdata_i = 0;
	(*prepped_data)[pdata_i] = 0;
	while (data_i < len)
	{
		(*prepped_data)[pdata_i] += (((uint32_t)(data[data_i])) <<
				((3 - (data_i % 4)) * 8));
		if (data_i % 4 == 3)
			(*prepped_data)[++pdata_i] = 0;
		data_i++;
	}
	return (pdata_i);
}
