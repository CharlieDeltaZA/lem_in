/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:27:07 by jhansen           #+#    #+#             */
/*   Updated: 2019/10/03 11:36:23 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

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

int			queue_explored(t_queue **queue)
{
	t_queue	*temp;

	temp = *queue;
	if (temp)
	{
		while (temp != NULL)
		{
			ft_putstr_col_fd(YELLOW, "Explored status: ", 1);	//
			ft_putnbr_col_fd(YELLOW, temp->explored, 1);		//
			ft_putchar('\n');									//
			if (temp->explored == 0)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}

void		add_weights(t_queue **queue)
{
	t_queue	*q_temp;

	q_temp = *queue;
	if (q_temp)
	{
		while (q_temp != NULL)
		{
			if (q_temp->room->weight != 0)
				q_temp->room->weight = q_temp->weight;
			q_temp = q_temp->next;
		}
	}
	else
		ft_putstr_col_fd(RED, "No queue found!! In add_weight function\n", 1);	//
}

int			path_find(t_queue **queue, t_rooms **room_head)
{
	t_rooms	*room;

	room = find_start(room_head);
	if (room == NULL)
		return (0);
	queue_start(queue, &room);
	while (queue_explored(queue) == 0)
	{
		room = next_link(queue);					//this will find the next room in the queue and return it. 
													//It will set the node in queue struct variable - explored = 1
		queue_links(queue, &room);					//this will ADD links to the queue from a room node.
													//In queue_links the new links weight is set as the origin room's weight + 1
		ft_putstr_col_fd(GREEN, "loop\n", 1);
	}
	add_weights(queue);			//not working? or its the printing?



	room = *room_head;								//debug
	ft_putchar('\n');
	while (room != NULL)
	{
		ft_putstr_col_fd(YELLOW, room->name, 1);
		ft_putstr_col_fd(YELLOW, " room's weight : ", 1);
		ft_putnbr_col_fd(YELLOW, room->weight, 1);
		ft_putchar('\n');
		room = room->next;
	}												//



	free_queue(queue);
	return (1);
}
