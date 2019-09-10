/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:28:06 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/04 22:29:00 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_queue.h"

t_queue	*ft_queue_init(void)
{
	t_queue	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->first = NULL;
	ret->last = NULL;
	return (ret);
}
