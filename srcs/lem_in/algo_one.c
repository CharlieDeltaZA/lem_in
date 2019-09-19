/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:27:07 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/19 16:18:24 by jhansen          ###   ########.fr       */
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
			if (temp->wheight < 1)
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
	room->wheight = ++wheight;
	while (all_explored(room_head) == 0)
	{
		queue_links(queue, room);  		//1 means it's the start (will auto set explored and visisted to 1)
	}



	// ft_putendl(room->name);
	// ft_putnbr_nl(room->start);
	// ft_putnbr_nl(room->end);
	// ft_putnbr_nl(room->wheight);
	// t_queue	*temp;
	// temp = *queue;
	// while (temp)
	// {
	// 	ft_putendl(temp->room->name);
	// 	ft_putnbr_nl(temp->explored);
	// 	temp = temp->next;
	// }



	return (1);
}
