/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:49:40 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 11:42:06 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	ft_ssl_prep_4b_data(uint32_t **prepped_data, char *data, uint64_t len)
{
//	int	i;
//
//	i = 0;
//	while (i < (int)len)
//	{
//		(*prepped_data)[i] = (((uint32_t)(data[(i * 4)])) << 24) + 
//			(((uint32_t)(data[(i * 4) + 1])) << 16) +
//			(((uint32_t)(data[(i * 4) + 2])) << 8) + 
//			(uint32_t)(data[(i * 4) + 3]);
//		i++;
//	}
//	return (i);
	uint64_t data_i;
	int	pdata_i;

	data_i = 0;
	pdata_i = 0;
	while (data_i < len)
	{
		(*prepped_data)[pdata_i] += (((uint32_t)(data[data_i])) <<
				((3 - (data_i % 4)) * 8));
		if (data_i % 4)
			(*prepped_data)[++pdata_i] = 0;
		data_i++;
	}
	return (pdata_i);
}
