/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:21:03 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 11:32:21 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

typedef struct	s_node
{
	void			*content;
	struct s_node	*next;
}				t_node;

typedef struct	s_queue
{
	t_node	*first;
	t_node	*last;
}				t_queue;

int				ft_queue_is_empty(t_queue *queue);
t_queue			*ft_queue_init(void);
void			ft_queue_enqueue(t_queue *queue, void *content);
void			ft_queue_push(t_queue *queue, void *content);
void			*ft_queue_dequeue(t_queue *queue);
void			*ft_queue_peek(t_queue *queue);

#endif
