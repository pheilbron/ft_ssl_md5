/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:06:10 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/05 20:20:56 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_ullpow(int base, int exp)
{
	unsigned long long	ret;

	ret = 1;
	while (exp-- > 0)
		ret *= (unsigned long long)base;
	return (ret);
}
