/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:04:55 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/05 14:08:19 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_str_capitalize(char *s)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = ft_strlen(s);
	if (!(ret = malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = (s[i] >= 'a' && s[i] <= 'z' ? ft_toupper(s[i]) : s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
