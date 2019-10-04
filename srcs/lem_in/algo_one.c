/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:27:07 by jhansen           #+#    #+#             */
/*   Updated: 2019/10/04 23:43:05 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int			path_find(t_rooms **room_head)
{
	t_rooms	*start;
	t_rooms	*end;
	t_queue	*queue;
	t_links	*temp;

	start = find_start(room_head);
	end = start;
	while (end->end != 1)
		end = end->next;
	queue = queue_node(start);
	start->weight = 1;
	while (queue && end->weight == 0)
	{
		temp = queue->room->links;
		while (temp)
		{
			if (temp->room->weight == 0)
				queue_add(queue, temp->room);
			temp = temp->next;
		}
		queue_remove(&queue);
	}
	free_queue(&queue);
	if (!(end->weight))
		return (0);
	return (1);
}
