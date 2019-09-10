/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llpow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:42:59 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/04 16:43:34 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

long long	ft_llpow(int base, int exp)
{
	long long	ret;

	ret = 1;
	while (exp-- > 0)
		ret *= (long long)base;
	return (ret);
}
