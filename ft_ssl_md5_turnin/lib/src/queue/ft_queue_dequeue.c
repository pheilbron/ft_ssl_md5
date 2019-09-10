/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_dequeue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:30:32 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 11:31:38 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_queue.h"

void	*ft_queue_dequeue(t_queue *queue)
{
	t_node	*temp;
	void	*content;

	if (!ft_queue_is_empty(queue))
	{
		content = queue->first->content;
		temp = queue->first;
		queue->first = queue->first->next;
		if (!queue->first)
			queue->last = NULL;
		free(temp);
		return (content);
	}
	return (NULL);
}
