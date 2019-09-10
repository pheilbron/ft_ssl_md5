/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_enqueue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:29:16 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 11:31:11 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_queue.h"

void	ft_queue_enqueue(t_queue *queue, void *content)
{
	t_node	*new;

	if ((new = malloc(sizeof(*new))))
	{
		new->content = content;
		new->next = NULL;
		if (ft_queue_is_empty(queue))
			queue->first = new;
		else
			queue->last->next = new;
		queue->last = new;
	}
}
