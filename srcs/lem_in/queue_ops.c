/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:55:29 by jhansen           #+#    #+#             */
/*   Updated: 2020/01/07 13:30:37 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		queue_add(t_queue *queue, t_rooms *room)
{
	if (!queue)
	{
		queue = queue_node(room);
		return ;
	}
	while (queue->next != NULL)
	{
		if (queue->room == room)
			return ;
		queue = queue->next;
	}
	queue->next = queue_node(room);
}

t_queue		*queue_node(t_rooms *room)
{
	t_queue	*node;

	if (room)
	{
		node = (t_queue *)malloc(sizeof(t_queue));
		node->room = room;
		node->next = NULL;
		return (node);
	}
	return (NULL);
}

t_rooms		*find_start(t_rooms **rooms)
{
	t_rooms	*head;

	head = *rooms;
	if (head)
	{
		while (head != NULL)
		{
			if (head->start == 1)
				return (head);
			head = head->next;
		}
	}
	return (NULL);
}

void		queue_remove(t_queue **queue)
{
	t_queue	*temp;

	if (!queue)
		return ;
	temp = (*queue)->next;
	free(*queue);
	*queue = temp;
}

void		free_queue(t_queue **queue)
{
	t_queue	*temp;
	t_queue	*next;

	temp = *queue;
	next = NULL;
	if (temp)
	{
		while (temp != NULL)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		*queue = NULL;
	}
}
