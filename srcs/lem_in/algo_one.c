/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:27:07 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/19 14:12:31 by jhansen          ###   ########.fr       */
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

int			path_find(t_queue **queue, t_rooms **room_head)
{
	t_rooms	*rooms;
	t_queue	*temp;

	rooms = find_start(room_head);
	if (rooms == NULL)
		return (0);
	//do stuff
	return (1);
}
