/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:32:20 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 11:31:01 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_queue.h"

void	*ft_queue_peek(t_queue *queue)
{
	if (ft_queue_is_empty(queue))
		return (NULL);
	return (queue->first->content);
}
