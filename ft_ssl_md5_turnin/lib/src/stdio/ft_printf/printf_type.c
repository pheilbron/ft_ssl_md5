/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:39:47 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 19:04:00 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_data_lmod(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 't' || c == 'z' ||
			c == 'L');
}

int	is_data_conversion(char c)
{
	return ((c >= 'b' && c <= 'd') || (c >= 'B' && c <= 'D') || c == 'f' ||
			c == 'F' || c == 'i' || (c >= 'n' && c <= 'p') || c == 'O' ||
			c == 'r' || c == 's' || c == 'S' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == '%');
}

int	is_data_flag(char c)
{
	return (c == '0' || c == '#' || c == '-' || c == '+' || c == ' ');
}

int	is_con_indicator(char c)
{
	return (c == '%' || c == '{');
}
