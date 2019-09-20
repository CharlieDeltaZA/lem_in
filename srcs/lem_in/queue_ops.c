/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:55:29 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/20 13:39:18 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		add_tail(t_queue **head, t_queue *node)
{
	t_queue	*temp;

	if (!(head) || (!(node)))
		return ;
	if (*head)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

static t_queue	*create_node(t_rooms *room)
{
	t_queue	*node;

	node = (t_queue *)malloc(sizeof(t_queue));
	if (node)
	{
		node->room = room;
		node->explored = 0;
		node->next = NULL;
	}
	return (node);
}

void			queue_links(t_queue **queue, t_rooms **curr_room, int wheight)
{
	t_queue	*node;
	t_links	*link;
	t_rooms	*room;

	room = *curr_room;
	link = NULL;
	if (room->links)
	{
		link = room->links;
		while (link != NULL)
		{
			if (*queue)
			{
				node = create_node(room);
				add_tail(queue, node);     			//might be a problem with the end room
			}
			else
				*queue = create_node(room);
			link = link->next;
		}
	}



	ft_putstr("Wheight before: ");
	ft_putnbr_col_fd(RED, room->wheight, 1);
	ft_putchar('\n');
	room->wheight = wheight;					//works here
	ft_putstr("Wheight after: ");
	ft_putnbr_col_fd(RED, room->wheight, 1);
	ft_putchar('\n');
}

t_rooms		*next_link(t_queue **queue)
{
	t_queue	*temp;

	temp = *queue;
	while (temp != NULL)
	{
		if (temp->explored == 0)
		{
			temp->explored = 1;			//might be a problem with the end room
			return (temp->room);
		}
		temp = temp->next;
	}
	return (NULL);
}

int			queue_explored(t_queue **queue)
{
	t_queue	*temp;

	temp = *queue;
	while (temp != NULL)
	{
		if (temp->explored == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}
