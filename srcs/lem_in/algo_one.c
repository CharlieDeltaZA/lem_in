/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:27:07 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/20 11:51:42 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_rooms		*find_start(t_rooms **rooms)
{
    t_rooms	*head;

	if (*rooms)
	{
		head = *rooms;
    	while (head != NULL)
    	{
 			if (head->start == 1)
				return (head);
			head = head->next;
		}
	}
	return (NULL);
}

int			all_explored(t_rooms **rooms)
{
	t_rooms	*temp;

	if (*rooms)
	{
		temp = *rooms;
		while (temp != NULL)
		{
			if (temp->wheight == 0)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}

int			path_find(t_queue **queue, t_rooms **room_head)
{
	t_rooms	*room;
	int		wheight;

	wheight = 0;
	room = find_start(room_head);
	if (room == NULL)
		return (0);
	while (all_explored(room_head) == 0)
	{
		write(1, "1\n", 2);
		queue_links(queue, &room, ++wheight);			//this will find the links attached to the room and add it to the queue. 
														//In queue_links we set the room wheight. So each time all_explored is called it will see if every room has a wheight.
		room = next_link(queue);						//this will find the next room in the queue and return it. It will set the room node in queue struct variable - explored = 1
		if (room == NULL)
		{
			if (all_explored(room_head) == 0)
				ft_putendl_col_fd(RED, "Error: Queue has been explored but all rooms haven't been", 1);		//for debug
			break ;
		}
	}
	if (queue_explored(queue))
		free_queue(queue);
	else
		ft_putendl_col_fd(CYAN, "MORE ALGO", 1);
	return (1);
}
