/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:55:35 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 11:30:52 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_queue.h"

void	ft_queue_push(t_queue *queue, void *content)
{
	t_node	*new;

	if ((new = malloc(sizeof(*new))))
	{
		new->content = content;
		if (!ft_queue_is_empty(queue))
			new->next = queue->first;
		else
		{
			new->next = NULL;
			queue->last = new;
		}
		queue->first = new;
	}
}
